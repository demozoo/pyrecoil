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
#include "formats.h"

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
	Image *image;
	MagickSizeType content_len;
	RECOIL *recoil;
	unsigned char *content;
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

	content_len = GetBlobSize(image);
	if (content_len > RECOIL_MAX_CONTENT_LENGTH)
		ThrowReaderException(CorruptImageError, "FileDecodingError");
	if (content_len == 0) /* failed to get file length */
		content_len = RECOIL_MAX_CONTENT_LENGTH;
	recoil = RECOIL_New();
	if (recoil == NULL)
		ThrowReaderException(ResourceLimitError, "MemoryAllocationFailed");
	content = malloc(content_len);
	if (content == NULL) {
		RECOIL_Delete(recoil);
		ThrowReaderException(ResourceLimitError, "MemoryAllocationFailed");
	}
	content_len = ReadBlob(image, content_len, content);
	if (content_len < 0) {
		free(content);
		RECOIL_Delete(recoil);
		ThrowReaderException(CorruptImageError, "UnableToReadImageData");
	}
	if (!RECOIL_Decode(recoil, image_info->filename, content, content_len)) {
		free(content);
		RECOIL_Delete(recoil);
		ThrowReaderException(CorruptImageError, "FileDecodingError");
	}
	free(content);

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
} formats[] = { MAGICK_RECOIL_FORMATS };

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
