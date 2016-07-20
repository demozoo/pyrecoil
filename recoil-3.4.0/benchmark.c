/*
 * benchmark.c - RECOIL benchmark
 *
 * Copyright (C) 2013-2015  Piotr Fusik and Adrian Matoga
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

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "recoil-stdio.h"

int main(int argc, char **argv)
{
	RECOIL *recoil;
	int i;
	if (argc < 2) {
		fprintf(stderr, "benchmark: no input files\n");
		return 1;
	}
	recoil = RECOILStdio_New();
	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		FILE *fp;
		static unsigned char content[RECOIL_MAX_CONTENT_LENGTH];
		int content_len;
		static unsigned char indexes[RECOIL_MAX_PIXELS_LENGTH];
		int colors;
		clock_t start_time;
		clock_t decode_time;
		clock_t colors_time;
		clock_t palette_time;
		clock_t decode2_time;
		clock_t palette2_time;
		clock_t colors2_time;

		if (strcmp(arg, "--help") == 0) {
			printf("Usage: benchmark FILE...\n");
			return 0;
		}

		fp = fopen(arg, "rb");
		if (fp == NULL) {
			fprintf(stderr, "benchmark: cannot open %s\n", arg);
			return 1;
		}
		content_len = fread(content, 1, sizeof(content), fp);
		fclose(fp);

		start_time = clock();
		if (!RECOIL_Decode(recoil, arg, content, content_len)) {
			fprintf(stderr, "benchmark: error decoding %s\n", arg);
			return 1;
		}
		decode_time = clock();
		colors = RECOIL_GetColors(recoil);
		colors_time = clock();
		RECOIL_ToPalette(recoil, indexes);
		palette_time = clock();

		RECOIL_Decode(recoil, arg, content, content_len);
		decode2_time = clock();
		RECOIL_ToPalette(recoil, indexes);
		palette2_time = clock();
		if (RECOIL_GetColors(recoil) != colors) {
			fprintf(stderr, "benchmark: RECOIL_GetColors failed for %s\n", arg);
			return 1;
		}
		colors2_time = clock();

		printf("%3dx%3d %4d colors Decode=%2ld,%2ld GetColors=%2ld,%2ld ToPalette=%2ld,%2ld %s\n",
			RECOIL_GetWidth(recoil), RECOIL_GetHeight(recoil), colors,
			(  decode_time -    start_time) * 1000L / CLOCKS_PER_SEC, /* RECOIL_Decode time */
			( decode2_time -  palette_time) * 1000L / CLOCKS_PER_SEC, /* ditto, should be same */
			(  colors_time -   decode_time) * 1000L / CLOCKS_PER_SEC, /* RECOIL_GetColors time */
			( colors2_time - palette2_time) * 1000L / CLOCKS_PER_SEC, /* RECOIL_GetColors after RECOIL_Palette, should be smaller */
			(palette2_time -  decode2_time) * 1000L / CLOCKS_PER_SEC, /* RECOIL_GetPalette time */
			( palette_time -   colors_time) * 1000L / CLOCKS_PER_SEC, /* RECOIL_GetPalette after RECOIL_GetColors, should be smaller */
			arg);
	}
	return 0;
}
