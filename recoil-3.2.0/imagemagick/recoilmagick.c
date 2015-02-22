/*
 * recoilmagick.c - RECOIL coder for ImageMagick
 *
 * Copyright (C) 2009-2015  Piotr Fusik and Adrian Matoga
 *
 * This file is part of RECOIL (Retro Computer Image Library),
 * see http://recoil.sourceforge.net
 *
 * RECOIL is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * RECOIL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RECOIL; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "recoil.h"

#include "magick/studio.h"
#include "magick/blob.h"
#include "magick/blob-private.h"
#include "magick/colorspace.h"
#include "magick/exception.h"
#include "magick/exception-private.h"
#include "magick/image.h"
#include "magick/image-private.h"
#include "magick/list.h"
#include "magick/magick.h"
#include "magick/memory_.h"
#include "magick/monitor.h"
#include "magick/monitor-private.h"
#include "magick/quantum-private.h"
#include "magick/static.h"
#include "magick/string_.h"
#include "magick/module.h"

static MagickBooleanType IsRECOIL(const unsigned char *magick, const size_t length)
{
	/* TODO: Should we really perform checks, having only seven bytes of file? */
	return MagickTrue;
}

static Image *ReadRECOILImage(const ImageInfo *image_info, ExceptionInfo *exception)
{
	unsigned char content[RECOIL_MAX_CONTENT_LENGTH];
	int content_len;
	RECOIL *recoil;
	Image *image;
	PixelPacket *q;
	const int *pixels;
	int num_pixels;
	int i;

	assert(image_info != NULL);
	assert(image_info->signature == MagickSignature);
	if (image_info->debug)
		LogMagickEvent(TraceEvent, GetMagickModule(), "%s", image_info->filename);
	assert(exception != NULL);
	assert(exception->signature == MagickSignature);
	image = AcquireImage(image_info);
	if (!OpenBlob(image_info, image, ReadBinaryBlobMode, exception)) {
		(void) DestroyImageList(image);
		return NULL;
	}

	content_len = ReadBlob(image, RECOIL_MAX_CONTENT_LENGTH, content);
	if (content_len < 0)
		ThrowReaderException(CorruptImageError, "UnableToReadImageData");
	recoil = RECOIL_New();
	if (recoil == NULL)
		ThrowReaderException(ResourceLimitError, "MemoryAllocationFailed");
	if (!RECOIL_Decode(recoil, image_info->filename, content, content_len)) {
		RECOIL_Delete(recoil);
		ThrowReaderException(CorruptImageError, "FileDecodingError");
	}

	image->depth = 8;
	if (!SetImageExtent(image, RECOIL_GetWidth(recoil), RECOIL_GetHeight(recoil))) {
		InheritException(exception, &image->exception);
		RECOIL_Delete(recoil);
		(void) DestroyImageList(image);
		return NULL;
	}

	q = QueueAuthenticPixels(image, 0, 0, image->columns, image->rows, exception);
	if (q == NULL) {
		RECOIL_Delete(recoil);
		(void) DestroyImageList(image);
		return NULL;
	}

	pixels = RECOIL_GetPixels(recoil);
	num_pixels = image->columns * image->rows;
	for (i = 0; i < num_pixels; i++) {
		int rgb = pixels[i];
		q[i].red = ScaleCharToQuantum((unsigned char) (rgb >> 16));
		q[i].green = ScaleCharToQuantum((unsigned char) (rgb >> 8));
		q[i].blue = ScaleCharToQuantum((unsigned char) rgb);
	}
	RECOIL_Delete(recoil);
	SyncAuthenticPixels(image, exception);

	CloseBlob(image);
	return GetFirstImageInList(image);
}

static const struct Format {
	const char *name;
	const char *description;
} formats[] = {
	{ "256", "80x96, 256 colors" },
	{ "3", "256x192, 8 colors, 3 frames" },
	{ "4BT", "GoDot; 320x200, 16 colors" },
	{ "4MI", "AtariTools-800 4 mono missiles" },
	{ "4PL", "AtariTools-800 4 mono players" },
	{ "4PM", "AtariTools-800 4 mono players and 4 mono missiles" },
	{ "64C", "8x8 font, mono" },
	{ "A4R", "Anime 4ever; 80x256, 16-level grayscale, compressed" },
	{ "A64", "Wigmore Artist 64; 160x200, 16 colors" },
	{ "AAS", "Art Studio; 320x200, 16 colors" },
	{ "ACBM", "Amiga Continuous Bitmap" },
	{ "ACS", "AtariTools-800 4x8 font, 4 colors" },
	{ "AFL", "AFLI-editor v2.0 by Topaz Beerlin; 296x200, 16 colors" },
	{ "AGP", "AtariTools-800 graphic" },
	{ "ALL", "Graph; 160x192, 5 colors" },
	{ "AMI", "Amica Paint; 160x200, 16 colors, compressed" },
	{ "AP2", "80x96, 256 colors" },
	{ "AP3", "80x192, 256 colors, 2 frames" },
	{ "APC", "Any Point, Any Color; 80x96, 256 colors, 2 frames" },
	{ "APL", "Atari Player Editor; up to 16 16x48 frames, 4 colors" },
	{ "APP", "80x192, 256 colors, 2 frames, compressed" },
	{ "APV", "80x192, 256 colors, 2 frames" },
	{ "ART", "Art Studio or Art Director or Ascii-Art Editor or Artist by David Eaton" },
	{ "ATR", "ZX Spectrum attributes" },
	{ "BB0", "Mode 0; 640x256, mono" },
	{ "BB1", "Mode 1; 320x256, 4 colors" },
	{ "BB2", "Mode 2; 160x256, 8 colors" },
	{ "BB4", "Mode 4; 320x256, mono" },
	{ "BB5", "Mode 5; 160x256, 4 colors" },
	{ "BBG", "LdPic" },
	{ "BFLI", "Big FLI; 148x400, 16 colors" },
	{ "BG9", "160x192, 16-level grayscale" },
	{ "BGP", "Bugbiter APAC239i; 80x239, 256 colors, 2 frames" },
	{ "BKG", "Movie Maker background; 160x96, 4 colors" },
	{ "BL1", "DEGAS Elite block; 16 colors" },
	{ "BL2", "DEGAS Elite block; 4 colors" },
	{ "BL3", "DEGAS Elite block; mono" },
	{ "BML", "FLI Graph 2.2 by Blackmail; 148x200, 16 colors" },
	{ "BRU", "DEGAS Elite brush; 8x8, mono" },
	{ "CA1", "CrackArt; 320x200, 16 colors, compressed" },
	{ "CA2", "CrackArt; 640x200, 4 colors, compressed" },
	{ "CA3", "CrackArt; 640x400, mono, compressed" },
	{ "CCI", "Champions' Interlace; 160x192, 2 frames, compressed" },
	{ "CDU", "CDU-Paint; 160x200, 16 colors" },
	{ "CH4", "4x8 font; mono" },
	{ "CH6", "6x8 font; mono" },
	{ "CH8", "8x8 font; mono" },
	{ "CHE", "Cheese; 160x200, 16 colors" },
	{ "CHR", "Blazing Paddles font; mono" },
	{ "CIN", "Champions' Interlace; 160x192 or 160x200, 2 frames" },
	{ "CPR", "Trzmiel; 320x192, mono, compressed" },
	{ "CPT", "Canvas; compressed" },
	{ "CWG", "Create with Garfield; 160x200, 16 colors" },
	{ "DC1", "DuneGraph; 320x200, 256 colors, compressed" },
	{ "DD", "Doodle; 320x200, 16 colors" },
	{ "DEL", "DelmPaint; 320x240, 256 colors, compressed" },
	{ "DG1", "DuneGraph; 320x200, 256 colors" },
	{ "DGC", "DuneGraph; 320x200, 256 colors, compressed" },
	{ "DGI", "Digi Paint; 80x192, 256 colors, 2 frames" },
	{ "DGP", "Digi Paint; 80x192, 256 colors, 2 frames" },
	{ "DGU", "DuneGraph; 320x200, 256 colors" },
	{ "DHR", "Double High-Resolution; 560x192, mono" },
	{ "DIN", "320x192, 10 colors, 2 frames" },
	{ "DLM", "Dir Logo Maker; 88x128, mono" },
	{ "DLP", "Drazlace; up to 320x200, 2 frames, compressed" },
	{ "DOL", "Dolphin Ed; 160x200, 16 colors" },
	{ "DOO", "Doodle; 640x400, mono" },
	{ "DPH", "DelmPaint; 640x480, 256 colors, compressed" },
	{ "DRG", "Atari CAD; 320x160, mono" },
	{ "DRL", "Drazlace; up to 320x200, 2 frames" },
	{ "DRP", "Drazpaint; 160x200, 16 colors, compressed" },
	{ "DRZ", "Drazpaint; 160x200, 16 colors" },
	{ "DU1", "416x273, 136 colors, 2 frames" },
	{ "DU2", "832x273, 10 colors, 2 frames" },
	{ "DUO", "416x273, 136 colors, 2 frames" },
	{ "ECI", "ECI Graphic Editor; 296x200, 2 frames" },
	{ "ECP", "ECI Graphic Editor; 296x200, 2 frames, compressed" },
	{ "EPA", "Award BIOS logo" },
	{ "ESC", "EscalPaint; 80x192, 256 colors, 2 frames" },
	{ "FD2", "FLI Designer; 148x200, 16 colors" },
	{ "FFLI", "148x200, 2 frames" },
	{ "FGS", "Fun Graphics Machine; 320x200, mono" },
	{ "FLI", "Flexible Line Interpratation; 148x200, 16 colors" },
	{ "FNT", "8x8 font, mono" },
	{ "FP2", "Funpaint 2; 148x200, 16 colors, compressed" },
	{ "FPT", "Face Painter; 160x200, 16 colors" },
	{ "FTC", "Falcon True Color; 384x240, 65536 colors" },
	{ "FUN", "Funpaint; 296x200, 2 frames, compressed" },
	{ "FWA", "Fun with Art; 160x192, 128 colors" },
	{ "G09", "160x192, 16-level grayscale" },
	{ "G10", "Graphics 10; up to 80x240, 9 colors" },
	{ "G11", "Graphics 11; up to 80x240, 16 colors" },
	{ "GCD", "Gigacad; 320x200, mono" },
	{ "GFB", "DeskPic" },
	{ "GG", "Koala Painter; 160x200, 16 colors, compressed" },
	{ "GHG", "Gephard Hires Graphics; up to 320x200, mono" },
	{ "GIG", "Gigapaint; 160x200, 16 colors" },
	{ "GIH", "Gigapaint; 320x200, mono" },
	{ "GOD", "GodPaint; 65536 colors" },
	{ "GR7", "Graphics 7; up to 160x120, 4 colors" },
	{ "GR8", "Graphics 8; up to 320x240, mono" },
	{ "GR9", "Graphics 9; up to 80x240, 16-level grayscale" },
	{ "GRP", "Screen 2; 256x192, 15 colors" },
	{ "GUN", "Gunpaint; 296x200, 2 frames" },
	{ "HAM6", "Hold-And-Modify 6; 4096 colors" },
	{ "HAM8", "Hold-And-Modify 8; 16777216 colors" },
	{ "HBM", "Hires Bitmap; 320x200, mono" },
	{ "HCI", "320x200, 5 colors, 2 frames" },
	{ "HED", "Hi-Eddi; 320x200, 16 colors" },
	{ "HFC", "Hires FLI by Crest; 296x112, 16 colors" },
	{ "HGB", "HinterGrundBild; 512x256, mono" },
	{ "HGR", "High Resolution; 280x192, mono" },
	{ "HIM", "Hires Manager by Cosmos; 296x192, 16 colors, compressed" },
	{ "HIP", "Hard Interlace Picture; 160x200, grayscale, 2 frames" },
	{ "HIR", "Hires; 320x200, mono" },
	{ "HLF", "Hires Interlace by Feniks; 320x200, 2 frames" },
	{ "HLR", "ZX Spectrum attributes gigascreen; 256x192, 2 frames" },
	{ "HPC", "Hi-Pic Creator; 320x200, 16 colors" },
	{ "HPM", "Grass' Slideshow; 160x192, 4 colors, compressed" },
	{ "HR", "256x239, 3 colors, 2 frames" },
	{ "HR2", "320x200, 5 colors, 2 frames" },
	{ "ICE", "Interlace Character Editor font, 2 frames" },
	{ "ICN", "DEGAS Elite Icon or ICE CIN" },
	{ "IFF", "Interchange File Format" },
	{ "IFL", "C64 Gunpaint or ZX Spectrum Multicolor 8x2" },
	{ "IGE", "Interlace Graphics Editor; 128x96, 16 colors, 2 frames" },
	{ "IHE", "Interlace Hires Editor; 320x200, 3 colors, 2 frames" },
	{ "ILC", "80x192, 256 colors, 2 frames" },
	{ "IMG", "GEM Bit Image or ZX Spectrum Gigascreen" },
	{ "IMN", "ICE MIN; 160x192, 80 colors, 2 frames" },
	{ "INFO", "Amiga Icon; 8 colors" },
	{ "ING", "ING 15; 160x200, 7 colors, 2 frames" },
	{ "INP", "160x200, 7 colors, 2 frames" },
	{ "INT", "INT95a; up to 160x239, 16 colors, 2 frames" },
	{ "IP2", "ICE PCIN+; 160x192, 45 colors, 2 frames" },
	{ "IPC", "ICE PCIN; 160x192, 35 colors, 2 frames" },
	{ "IPH", "Interpaint; 320x200, 16 colors" },
	{ "IPT", "Interpaint; 160x200, 16 colors" },
	{ "IR2", "Super IRG 2; 160x192, 25 colors, 2 frames" },
	{ "IRG", "Super IRG; 160x192, 15 colors, 2 frames" },
	{ "ISM", "Image System; 160x200, 16 colors" },
	{ "IST", "Interlace Studio; 160x200, 2 frames" },
	{ "JGP", "Jet Graphics Planner; 8x16 tiles, 4 colors" },
	{ "JJ", "Doodle; 320x200, 16 colors, compressed" },
	{ "KOA", "Koala Painter; 160x200, 16 colors" },
	{ "LBM", "Interleaved Bitmap" },
	{ "LEO", "Larka Edytor Obiektow trybu $4+; 8x16 tiles, 5 colors" },
	{ "LP3", "Logo Painter 3/3+; 160x400, 4 colors" },
	{ "LUM", "Technicolor Dream luminance; 80x96, 16-level grayscale" },
	{ "MAC", "MacPaint; 576x720, mono, compressed" },
	{ "MAX", "XL-Paint MAX; 160x192, 2 frames, compressed" },
	{ "MBG", "Mad Designer; 512x256, mono" },
	{ "MC", "Multicolor 8x1; 256x192, 15 colors" },
	{ "MCH", "Graph2Font; up to 176x240, 128 colors" },
	{ "MCI", "True Paint; 320x200, 2 frames" },
	{ "MCP", "McPainter; 160x200, 16 colors, 2 frames" },
	{ "MCPP", "Paradox; 160x100, 16 colors" },
	{ "MCS", "160x192, 9 colors" },
	{ "MG1", "MultiArtist; 256x192, 2 frames" },
	{ "MG2", "MultiArtist; 256x192, 2 frames" },
	{ "MG4", "MultiArtist; 256x192, 2 frames" },
	{ "MG8", "MultiArtist; 256x192, 2 frames" },
	{ "MGP", "Magic Painter; 160x96, 4 colors with optional rainbow effect" },
	{ "MIC", "Micro Illustrator; up to 160x240, 4 colors" },
	{ "MIL", "Micro Illustrator; 160x200, 16 colors" },
	{ "MIS", "AtariTools-800 missile; 2x240, mono" },
	{ "MLE", "Multi-Lace Editor; 320x56, 10 colors, 2 frames" },
	{ "MON", "Mono Magic; 320x200, mono" },
	{ "MPP", "Multi Palette Picture; up to 416x273, 1 or 2 frames" },
	{ "MSP", "Microsoft Paint version 1 or 2; mono" },
	{ "NEO", "NEOchrome" },
	{ "NLQ", "Daisy-Dot; 19x16 font, mono" },
	{ "OCP", "Advanced Art Studio; 160x200, 16 colors" },
	{ "P", "Sinclair BASIC; 256x192, mono" },
	{ "P4I", "Up to 320x200, 121 colors" },
	{ "P64", "Picasso 64; 160x200, 16 colors" },
	{ "PAC", "STAD; 640x400, mono, compressed" },
	{ "PC1", "DEGAS Elite; 320x200, 16 colors, compressed" },
	{ "PC2", "DEGAS Elite; 640x200, 4 colors, compressed" },
	{ "PC3", "DEGAS Elite; 640x400, mono, compressed" },
	{ "PCS", "PhotoChrome; 320x199, 1 or 2 frames, compressed" },
	{ "PGC", "Atari Portfolio; 240x64, mono, compressed" },
	{ "PGF", "Atari Portfolio; 240x64, mono" },
	{ "PI", "Blazing Paddles; 160x200, 16 colors" },
	{ "PI1", "DEGAS; up to 416x560, 16 colors" },
	{ "PI2", "DEGAS; 640x200, 4 colors" },
	{ "PI3", "DEGAS; 640x400, mono" },
	{ "PI4", "Fuckpaint; 320x240 or 320x200, 256 colors" },
	{ "PI9", "Fuckpaint; 320x240 or 320x200, 256 colors" },
	{ "PIC", "Koala MicroIllustrator; 160x192, 4 colors, compressed" },
	{ "PL4", "320x200, 256 colors, 2 frames, compressed" },
	{ "PLA", "AtariTools-800 player; 8x240, mono" },
	{ "PLM", "Plama 256; 80x96, 256 colors" },
	{ "PMD", "PMG Designer by Henryk Karpowicz" },
	{ "PMG", "Paint Magic; 160x200, 16 colors" },
	{ "PZM", "Pryzm Artist; 80x192, 256 colors, 2 frames" },
	{ "RAW", "XL-Paint MAX; 160x192, 16 colors, 2 frames" },
	{ "RGB", "Atari 8-bit or ZX Spectrum; 3 frames" },
	{ "RIP", "Rocky Interlace Picture; up to 320x239, 1 or 2 frames" },
	{ "RM0", "Rambrandt; 160x96, 99 colors" },
	{ "RM1", "Rambrandt; 80x192, 256 colors" },
	{ "RM2", "Rambrandt; 80x192, 104 colors" },
	{ "RM3", "Rambrandt; 80x192, 128 colors" },
	{ "RM4", "Rambrandt; 160x192, 99 colors" },
	{ "RP", "Rainbow Painter; 160x200, 16 colors" },
	{ "RPM", "Run Paint; 160x200, 16 colors" },
	{ "RYS", "Mamut; 160x96, 4 colors" },
	{ "SAR", "Saracen Paint; 160x200, 16 colors" },
	{ "SC2", "Screen 2; 256x192, 15 colors" },
	{ "SC8", "Screen 8; 256x212, 256 colors" },
	{ "SCA", "Screen 10; 256x212, 12515 colors" },
	{ "SCC", "Screen 12; 256x212, 19268 colors" },
	{ "SCR", "256x192, 15 colors" },
	{ "SCS4", "Mode 4; 256x192, 16 colors" },
	{ "SGE", "Semi-Graphic logos Editor; 320x192, mono" },
	{ "SHC", "SAMAR Hi-res Interlace with Map of Colours; 320x192, 2 frames" },
	{ "SHP", "Blazing Paddles or Movie Maker shapes" },
	{ "SHR", "320x200, 256 colors" },
	{ "SIF", "Super-IRG 4x8 font; 4 colors, 2 frames" },
	{ "SPC", "Spectrum 512 Compressed or The Graphics Magician Picture Painter" },
	{ "SPS", "Spectrum 512 Smooshed; 320x199, 512 colors, compressed" },
	{ "SPU", "Spectrum 512; 320x199, 512 colors" },
	{ "SR8", "Graph Saurus; 256x212, 256 colors, compressed" },
	{ "SRS", "Screen 12; 256x212, 19268 colors" },
	{ "SXS", "16x16 font, mono" },
	{ "TIP", "Taquart Interlace Picture; up to 160x119, 2 frames" },
	{ "TN1", "Tiny Stuff; 320x200, 16 colors, compressed" },
	{ "TN2", "Tiny Stuff; 640x200, 4 colors, compressed" },
	{ "TN3", "Tiny Stuff; 640x400, mono, compressed" },
	{ "TNY", "Tiny Stuff; compressed" },
	{ "TRP", "EggPaint; 65536 colors" },
	{ "TRU", "IndyPaint; 65536 colors" },
	{ "WIG", "Wigmore Artist 64; 160x200, 16 colors" },
	{ "WND", "Blazing Paddles window; up to 160x192, 4 colors" },
	{ "VIC", "Generic C64; up to 320x200, 16 colors" },
	{ "VID", "Vidcom 64; 160x200, 16 colors" },
	{ "VZI", "VertiZontal Interlacing; 160x200, grayscale, 2 frames" },
	{ "XIMG", "Extended GEM Bit Image; compressed" },
	{ "XLP", "XL-Paint; 160x192 or 160x200, 7 colors, 2 frames, compressed" },
	{ "ZXP", "ZX-Paintbrush; 256x192, 15 colors" }
};

/* Workaround for MagickCore.h: it omits __declspec(dllexport) for MinGW.
   As a result, no symbol has __declspec(dllexport) and thus all are exported from the DLL. */
#ifdef _WIN32
#undef ModuleExport
#define ModuleExport __declspec(dllexport)
#endif

ModuleExport unsigned long RegisterRECOILImage(void)
{
	const struct Format *pf;
	for (pf = formats; pf < formats + sizeof(formats) / sizeof(formats[0]); pf++) {
		MagickInfo *entry = SetMagickInfo(pf->name);
		entry->decoder = ReadRECOILImage;
		entry->magick = IsRECOIL;
		entry->description = ConstantString(pf->description);
		entry->module = ConstantString("RECOIL");
		RegisterMagickInfo(entry);
	}	
	return MagickImageCoderSignature;
}

ModuleExport void UnregisterRECOILImage(void)
{
	const struct Format *pf;
	for (pf = formats; pf < formats + sizeof(formats) / sizeof(formats[0]); pf++)
		UnregisterMagickInfo(pf->name);
}
