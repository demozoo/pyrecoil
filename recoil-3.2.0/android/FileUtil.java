/*
 * FileUtil.java - RECOIL for Android
 *
 * Copyright (C) 2013  Piotr Fusik and Adrian Matoga
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

import android.net.Uri;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Enumeration;
import java.util.TreeSet;
import java.util.zip.ZipFile;
import java.util.zip.ZipEntry;

abstract class FileUtil
{
	static boolean isZip(String filename)
	{
		int n = filename.length();
		return n >= 4 && filename.regionMatches(true, n - 4, ".zip", 0, 4);
	}

	private static void listDirectory(File dir, TreeSet<String> directories, ArrayList<String> files) throws IOException
	{
		File[] entries = dir.listFiles();
		if (entries == null)
			throw new FileNotFoundException();
		for (File entry : entries) {
			String name = entry.getName();
			if (entry.isDirectory()) {
				if (directories != null)
					directories.add(name + '/');
			}
			else if (RECOIL.isOurFile(name))
				files.add(name);
			else if (directories != null && isZip(name))
				files.add(name);
		}
	}

	private static void listZipDirectory(File zipFile, String zipPath, TreeSet<String> directories, ArrayList<String> files) throws IOException
	{
		if (zipPath == null)
			zipPath = "";
		int zipPathLen = zipPath.length();
		ZipFile zip = new ZipFile(zipFile);
		try {
			Enumeration<? extends ZipEntry> entries = zip.entries();
			while (entries.hasMoreElements()) {
				ZipEntry entry = entries.nextElement();
				if (!entry.isDirectory()) {
					String name = entry.getName();
					if (name.startsWith(zipPath) && RECOIL.isOurFile(name)) {
						int i = name.indexOf('/', zipPathLen);
						if (i >= 0) {
							// file in a subdirectory
							if (directories != null) {
								// add subdirectory with the trailing slash
								directories.add(name.substring(zipPathLen, i + 1));
							}
						}
						else
							files.add(name.substring(zipPathLen));
					}
				}
			}
		}
		finally {
			zip.close();
		}
	}

	static ArrayList<String> list(Uri uri, TreeSet<String> directories) throws IOException
	{
		ArrayList<String> files = new ArrayList<String>();
		File file = new File(uri.getPath());
		if (file.isDirectory())
			listDirectory(file, directories, files);
		else
			listZipDirectory(file, uri.getFragment(), directories, files);
		Collections.sort(files);
		return files;
	}

	static Uri buildUri(Uri baseUri, String relativePath)
	{
		String path = baseUri.getPath();
		if (isZip(path)) {
			String zipPath = baseUri.getFragment();
			if (zipPath == null)
				zipPath = relativePath;
			else
				zipPath += relativePath;
			return baseUri.buildUpon().fragment(zipPath).build();
		}
		return Uri.fromFile(new File(path, relativePath));
	}
}
