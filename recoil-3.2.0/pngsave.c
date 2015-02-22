/*
 * pngsave.c - save PNG file
 *
 * Copyright (C) 2009-2013  Piotr Fusik and Adrian Matoga
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

#include <stdlib.h>
#include <png.h>

#include "pngsave.h"

static void RECOIL_Rgb2Png(png_colorp dest, const int *src, int length)
{
	int i;
	for (i = 0; i < length; i++) {
		int rgb = src[i];
		dest[i].red = (png_byte) (rgb >> 16);
		dest[i].green = (png_byte) (rgb >> 8);
		dest[i].blue = (png_byte) rgb;
	}
}

cibool RECOIL_SavePng(RECOIL *self, const char *filename)
{
	FILE *fp = fopen(filename, "wb");
	png_structp png_ptr;
	png_infop info_ptr;
	int width;
	int height;
	unsigned char indexes[RECOIL_MAX_PIXELS_LENGTH];
	const int *palette;
	png_bytep row_pointers[RECOIL_MAX_HEIGHT];
	int y;

	if (fp == NULL)
		return FALSE;
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		fclose(fp);
		return FALSE;
	}
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fclose(fp);
		png_destroy_write_struct(&png_ptr, NULL);
		return FALSE;
	}
	/* Set error handling. */
	if (setjmp(png_jmpbuf(png_ptr))) {
		/* If we get here, we had a problem writing the file */
		fclose(fp);
		png_destroy_write_struct(&png_ptr, &info_ptr);
		return FALSE;
	}
	png_init_io(png_ptr, fp);

	width = RECOIL_GetWidth(self);
	height = RECOIL_GetHeight(self);
	palette = RECOIL_ToPalette(self, indexes);
	if (palette == NULL) {
		png_color png_pixels[RECOIL_MAX_PIXELS_LENGTH];
		RECOIL_Rgb2Png(png_pixels, RECOIL_GetPixels(self), width * height);
		png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB,
			PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
		png_write_info(png_ptr, info_ptr);

		for (y = 0; y < height; y++)
			row_pointers[y] = (png_bytep) (png_pixels + y * width);
	}
	else {
		int colors = RECOIL_GetColors(self);
		int bit_depth = colors <= 2 ? 1
			: colors <= 4 ? 2
			: colors <= 16 ? 4
			: 8;
		png_color png_palette[256];
		RECOIL_Rgb2Png(png_palette, palette, colors);
		png_set_IHDR(png_ptr, info_ptr, width, height, bit_depth, PNG_COLOR_TYPE_PALETTE,
			PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
		png_set_PLTE(png_ptr, info_ptr, png_palette, colors);
		png_write_info(png_ptr, info_ptr);

		if (bit_depth < 8)
			png_set_packing(png_ptr);
		for (y = 0; y < height; y++)
			row_pointers[y] = indexes + y * width;
	}
	png_write_image(png_ptr, row_pointers);
	png_write_end(png_ptr, info_ptr);
	png_destroy_write_struct(&png_ptr, &info_ptr);
	fclose(fp);
	return TRUE;
}
