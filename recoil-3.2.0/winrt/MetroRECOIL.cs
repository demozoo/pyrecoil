/*
 * MetroRECOIL.cs - Windows Store application
 *
 * Copyright (C) 2014-2015  Piotr Fusik
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
using System.Reflection;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using Windows.ApplicationModel.Activation;
using Windows.Storage;
using Windows.Storage.Streams;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Media.Imaging;

using Recoil;

[assembly: AssemblyTitle("Windows Store RECOIL")]
//[assembly: AssemblyDescription("Shows images in native formats of classic computers")]
[assembly: AssemblyCompany("Piotr Fusik")]
[assembly: AssemblyProduct("RECOIL")]
[assembly: AssemblyCopyright("Copyright © 2014-2015")]
[assembly: AssemblyVersion(RECOIL.Version + ".0")]
[assembly: AssemblyFileVersion(RECOIL.Version + ".0")]

class MetroRECOIL : Application
{
	async Task ShowFile(StorageFile sf)
	{
		if (sf == null) {
			Exit();
			return;
		}

		// Read.
		byte[] content = new byte[RECOIL.MaxContentLength];
		int contentLength;
		using (IInputStream iis = await sf.OpenSequentialReadAsync()) {
			IBuffer buf = await iis.ReadAsync(content.AsBuffer(), (uint) RECOIL.MaxContentLength, InputStreamOptions.None);
			contentLength = (int) buf.Length;
		}

		// Decode.
		RECOIL recoil = new RECOIL();
		if (!recoil.Decode(sf.Name, content, contentLength))
			throw new Exception("Decoding error");
		int width = recoil.GetWidth();
		int height = recoil.GetHeight();
		int[] pixels = recoil.GetPixels();

		// Convert to BGRA.
		WriteableBitmap bitmap = new WriteableBitmap(width, height);
		byte[] line = new byte[width << 2];
		for (int x = 0; x < width; x++)
			line[(x << 2) + 3] = 0xff; // alpha
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int rgb = pixels[y * width + x];
				line[(x << 2)] = (byte) rgb;
				line[(x << 2) + 1] = (byte) (rgb >> 8);
				line[(x << 2) + 2] = (byte) (rgb >> 16);
			}
			line.CopyTo(0, bitmap.PixelBuffer, (uint) (y * width << 2), width << 2);
		}

		// Display.
		Image image = new Image();
		image.Source = bitmap;
		Window.Current.Content = image;
	}

	protected override async void OnLaunched(LaunchActivatedEventArgs args)
	{
		Window.Current.Activate();
		StorageFile sf = await FilePicker.PickFile();
		await ShowFile(sf);
	}

	protected override async void OnFileActivated(FileActivatedEventArgs args)
	{
		StorageFile sf = args.Files[0] as StorageFile;
		await ShowFile(sf);
	}

	public static void Main(string[] args)
	{
		Application.Start(p => new MetroRECOIL());
	}
}
