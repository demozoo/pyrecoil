/*
 * recoil-win32.c - Win32 API subclass of RECOIL
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

#include <windows.h>

#include "recoil-win32.h"

int SlurpFile(const char *filename, unsigned char *buffer, int len)
{
	HANDLE fh = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	BOOL ok;
	if (fh == INVALID_HANDLE_VALUE)
		return -1;
	ok = ReadFile(fh, buffer, len, (LPDWORD) &len, NULL);
	CloseHandle(fh);
	return ok ? len : -1;
}

typedef struct {
	int (*readFile)(RECOIL *self, const char *filename, unsigned char *content, int contentLength);
}
RECOILVtbl;

static int RECOILWin32_ReadFile(RECOIL *self, const char *filename, unsigned char *content, int contentLength)
{
	return SlurpFile(filename, content, contentLength);
}

RECOIL *RECOILWin32_New(void)
{
	RECOIL *self = RECOIL_New();
	if (self != NULL) {
		static const RECOILVtbl vtbl = { RECOILWin32_ReadFile };
		*(const RECOILVtbl **) self = &vtbl;
	}
	return self;
}
