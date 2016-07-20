/*
 * GalleryAdapter.java - RECOIL for Android
 *
 * Copyright (C) 2013-2016  Piotr Fusik and Adrian Matoga
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

import android.graphics.Bitmap;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Gallery;
import android.widget.ImageView;
import android.widget.TextView;

class GalleryAdapter extends BaseAdapter
{
	private final Viewer viewer;

	GalleryAdapter(Viewer viewer)
	{
		this.viewer = viewer;
	}

	public View getView(int position, View convertView, ViewGroup parent)
	{
		RECOIL recoil;
		try {
			recoil = viewer.decode(position);
		}
		catch (RECOILException ex) {
			TextView textView = (TextView) viewer.getLayoutInflater().inflate(R.layout.error, null);
			textView.setText(ex.getMessage());
			return textView;
		}

		int[] pixels = recoil.getPixels();
		int width = recoil.getWidth();
		int height = recoil.getHeight();

		// Set alpha
		int pixelsLength = width * height;
		for (int i = 0; i < pixelsLength; i++)
			pixels[i] |= 0xff000000;

		// Display
		Bitmap bitmap = Bitmap.createBitmap(pixels, width, height, Bitmap.Config.ARGB_8888);
		AndroidSupport.getInstance().setHasAlpha(bitmap, false);
		ImageView imageView = convertView instanceof ImageView ? (ImageView) convertView : new ImageView(viewer);
		imageView.setLayoutParams(new Gallery.LayoutParams(Gallery.LayoutParams.FILL_PARENT, Gallery.LayoutParams.FILL_PARENT));
		imageView.setImageBitmap(bitmap);
		return imageView;
	}

	public long getItemId(int position)
	{
		return position;
	}

	public Object getItem(int position)
	{
		return position;
	}

	public int getCount()
	{
		return viewer.getFileCount();
	}
}
