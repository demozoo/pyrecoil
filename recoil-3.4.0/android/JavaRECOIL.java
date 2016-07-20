/*
 * JavaRECOIL.java - RECOIL for Android
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

package net.sf.recoil;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.IOException;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

abstract class JavaRECOIL extends RECOIL
{
	abstract long getLength(String filename);

	abstract InputStream openFile(String filename) throws IOException;

	int readFileOrThrow(String filename, byte[] content, int contentLength) throws IOException
	{
		InputStream is = openFile(filename);
		int got = 0;
		try {
			while (got < contentLength) {
				int i = is.read(content, got, contentLength - got);
				if (i <= 0)
					break;
				got += i;
			}
		}
		finally {
			is.close();
		}
		return got;
	}

	@Override
	int readFile(String filename, byte[] content, int contentLength)
	{
		try {
			return readFileOrThrow(filename, content, contentLength);
		}
		catch (IOException ex) {
			return -1;
		}
	}

	boolean load(String filename) throws IOException
	{
		long longLength = getLength(filename);
		if (longLength > MAX_CONTENT_LENGTH)
			throw new IOException("File too long");
		int contentLength = (int) longLength;
		byte[] content = new byte[contentLength];
		contentLength = readFileOrThrow(filename, content, contentLength);
		return decode(filename, content, contentLength);
	}
}

class FileRECOIL extends JavaRECOIL
{
	@Override
	long getLength(String filename)
	{
		return new File(filename).length();
	}

	@Override
	InputStream openFile(String filename) throws IOException
	{
		return new FileInputStream(filename);
	}
}

class ZipRECOIL extends JavaRECOIL
{
	private final ZipFile zip;

	ZipRECOIL(ZipFile zip)
	{
		this.zip = zip;
	}

	@Override
	long getLength(String filename)
	{
		ZipEntry entry = zip.getEntry(filename);
		if (entry == null)
			return 0;
		return entry.getSize();
	}

	@Override
	InputStream openFile(String filename) throws IOException
	{
		ZipEntry entry = zip.getEntry(filename);
		if (entry == null)
			throw new FileNotFoundException(filename);
		return zip.getInputStream(entry);
	}
}
