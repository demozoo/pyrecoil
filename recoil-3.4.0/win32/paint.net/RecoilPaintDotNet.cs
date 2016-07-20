/*
 * RecoilPaintDotNet.cs - Paint.NET file type plugin
 *
 * Copyright (C) 2013-2016  Piotr Fusik
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

using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Reflection;
using System.Runtime.InteropServices;

using PaintDotNet;
using Recoil;

[assembly: AssemblyTitle("Paint.NET RECOIL plugin")]
//[assembly: AssemblyDescription("Decodes images in native formats of classic computers")]
[assembly: AssemblyCompany("Piotr Fusik")]
[assembly: AssemblyProduct("RECOIL")]
[assembly: AssemblyCopyright("Copyright © 2013-2016")]
[assembly: AssemblyVersion(RECOIL.Version + ".0")]
[assembly: AssemblyFileVersion(RECOIL.Version + ".0")]

namespace Recoil.PaintDotNet
{
	// Paint.NET gives us a Stream without the filename, so I create a distinct FileType object for each extension.
	// This could be optimized by considering alias extensions.

	class RecoilFileType : FileType
	{
		public RecoilFileType(string ext, string name) : base(name, FileTypeFlags.SupportsLoading, new string[] { ext })
		{
		}

		protected override Document OnLoad(System.IO.Stream input)
		{
			// Read.
			long longLength = input.Length;
			if (longLength > RECOIL.MaxContentLength)
				throw new Exception("File too long");
			int contentLength = (int) longLength;
			byte[] content = new byte[contentLength];
			contentLength = input.Read(content, 0, contentLength);

			// Decode.
			RECOIL recoil = new RECOIL();
			if (!recoil.Decode(DefaultExtension, content, contentLength))
				throw new Exception("Decoding error");
			int width = recoil.GetWidth();

			// Pass to Paint.NET.
			GCHandle pinnedPixels = GCHandle.Alloc(recoil.GetPixels(), GCHandleType.Pinned);
			using (Bitmap bitmap = new Bitmap(width, recoil.GetHeight(), width << 2, PixelFormat.Format32bppRgb, pinnedPixels.AddrOfPinnedObject())) {
				pinnedPixels.Free();
				return Document.FromImage(bitmap);
			}
		}
	}
}
