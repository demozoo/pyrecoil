/*
 * recoil-stdio.c - stdio subclass of RECOIL
 *
 * Copyright (C) 2015  Piotr Fusik
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

#include "recoil-stdio.h"

typedef struct {
	int (*readFile)(RECOIL *self, const char *filename, unsigned char *content, int contentLength);
}
RECOILVtbl;

static int RECOILStdio_ReadFile(RECOIL *self, const char *filename, unsigned char *content, int contentLength)
{
	FILE *fp = fopen(filename, "rb");
	if (fp == NULL)
		return -1;
	contentLength = fread(content, 1, contentLength, fp);
	fclose(fp);
	return contentLength;
}

RECOIL *RECOILStdio_New(void)
{
	RECOIL *self = RECOIL_New();
	if (self != NULL) {
		static const RECOILVtbl vtbl = { RECOILStdio_ReadFile };
		*(const RECOILVtbl **) self = &vtbl;
	}
	return self;
}
