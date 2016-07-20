/*
 * recoil2png.c - command-line converter of retro computer pictures to the PNG format
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "recoil-stdio.h"
#include "pngsave.h"

static RECOIL *recoil = NULL;
static const char *output_file = NULL;

static void print_help(void)
{
	printf(
		"Usage: recoil2png [OPTIONS] INPUTFILE...\n"
		"Options:\n"
		"-o FILE  --output=FILE   Set output file name\n"
		"-p FILE  --palette=FILE  Load Atari 8-bit palette (768 bytes)\n"
		"-h       --help          Display this information\n"
		"-v       --version       Display version information\n"
	);
}

static void fatal_error(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	fprintf(stderr, "recoil2png: ");
	vfprintf(stderr, format, args);
	fputc('\n', stderr);
	va_end(args);
	exit(1);
}

static int load_file(const char *filename, void *buffer, size_t buffer_len)
{
	FILE *fp = fopen(filename, "rb");
	int len;
	if (fp == NULL)
		fatal_error("cannot open %s", filename);
	len = fread(buffer, 1, buffer_len, fp);
	fclose(fp);
	return len;
}

static void load_palette(const char *filename)
{
	unsigned char atari8_palette[768 + 1];
	if (load_file(filename, atari8_palette, sizeof(atari8_palette)) != 768)
		fatal_error("%s: palette file must be 768 bytes", filename);
	RECOIL_SetAtari8Palette(recoil, atari8_palette);
}

static void process_file(const char *input_file)
{
	static unsigned char content[RECOIL_MAX_CONTENT_LENGTH];
	int content_len = load_file(input_file, content, sizeof(content));
	if (!RECOIL_Decode(recoil, input_file, content, content_len))
		fatal_error("%s: file decoding error", input_file);

	if (output_file == NULL) {
		static char output_default[FILENAME_MAX];
		int i;
		int dotp = 0;
		for (i = 0; input_file[i] != '\0' && i < FILENAME_MAX - 5; i++)
			if ((output_default[i] = input_file[i]) == '.')
				dotp = i;
		strcpy(output_default + (dotp == 0 ? i : dotp), ".png");
		output_file = output_default;
	}
	if (!RECOIL_SavePng(recoil, output_file))
		fatal_error("cannot write %s", output_file);
	output_file = NULL;
}

int main(int argc, char **argv)
{
	cibool no_input_files = TRUE;
	int i;
	recoil = RECOILStdio_New();
	if (recoil == NULL)
		fatal_error("recoil2png: out of memory");
	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (arg[0] != '-') {
			process_file(arg);
			no_input_files = FALSE;
		}
		else if (arg[1] == 'o' && arg[2] == '\0')
			output_file = argv[++i];
		else if (strncmp(arg, "--output=", 9) == 0)
			output_file = arg + 9;
		else if (arg[1] == 'p' && arg[2] == '\0')
			load_palette(argv[++i]);
		else if (strncmp(arg, "--palette=", 10) == 0)
			load_palette(arg + 10);
		else if ((arg[1] == 'h' && arg[2] == '\0')
			|| strcmp(arg, "--help") == 0) {
			print_help();
			no_input_files = FALSE;
		}
		else if ((arg[1] == 'v' && arg[2] == '\0')
			|| strcmp(arg, "--version") == 0) {
			printf("recoil2png " RECOIL_VERSION "\n");
			no_input_files = FALSE;
		}
		else
			fatal_error("unknown option: %s", arg);
	}
	if (no_input_files) {
		print_help();
		return 1;
	}
	return 0;
}
