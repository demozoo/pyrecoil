/*
 * Viewer.java - RECOIL for Android
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

import android.app.Activity;
import android.app.AlertDialog;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Gallery;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.TreeSet;
import java.util.zip.ZipFile;

class RECOILException extends Exception
{
	RECOILException(String message)
	{
		super(message);
	}
}

public class Viewer extends Activity implements AdapterView.OnItemSelectedListener
{
	private Uri baseUri;
	private ArrayList<String> filenames;
	private Gallery gallery;
	private TreeSet<String> favorites;
	private MenuItem favoriteMenuItem;

	private String split(Uri uri)
	{
		String filename = uri.getFragment();
		if (filename == null)
			filename = uri.getPath();

		int i = filename.lastIndexOf('/') + 1;
		// nice hack - the following substrings do what we want if there is no slash
		String path = filename.substring(0, i);
		filename = filename.substring(i);

		if (uri.getFragment() == null)
			baseUri = Uri.fromFile(new File(path));
		else
			baseUri = uri.buildUpon().fragment(path).build();
		return filename;
	}

	int getFileCount()
	{
		return filenames.size();
	}

	RECOIL decode(int position) throws RECOILException
	{
		Uri uri = FileUtil.buildUri(baseUri, filenames.get(position));
		String filename = uri.getPath();
		try {
			ZipFile zip = null;
			JavaRECOIL recoil;
			try {
				if (FileUtil.isZip(filename)) {
					zip = new ZipFile(filename);
					recoil = new ZipRECOIL(zip);
					filename = uri.getFragment();
				}
				else
					recoil = new FileRECOIL();
				if (!recoil.load(filename))
					throw new RECOILException(getString(R.string.error_decoding_file, filename));
			}
			finally {
				if (zip != null)
					zip.close();
			}
			return recoil;
		}
		catch (IOException ex) {
			throw new RECOILException(getString(R.string.error_reading_file, filename));
		}
	}

	private void setFavoriteIcon(String filename)
	{
		if (favoriteMenuItem != null) {
			Uri uri = FileUtil.buildUri(baseUri, filename);
			FileUtil.setFavoriteIcon(favoriteMenuItem, favorites.contains(uri.toString()));
		}
	}

	public void onItemSelected(AdapterView<?> parent, View view, int position, long id)
	{
		String filename = filenames.get(position);
		setTitle(getString(R.string.viewing_title, filename));
		setFavoriteIcon(filename);
	}

	public void onNothingSelected(AdapterView<?> parent)
	{
		// can we ever get here?
	}

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		AndroidSupport.getInstance().setDisplayHomeAsUpEnabled(this);

		Uri uri = getIntent().getData();
		String filename = split(uri);
		try {
			filenames = FileUtil.list(baseUri, null);
		}
		catch (IOException ex) {
			setContentView(R.layout.access_denied);
			return;
		}

		favorites = new TreeSet<String>(FileUtil.getUserFavorites(this));

		gallery = (Gallery) getLayoutInflater().inflate(R.layout.gallery, null);
		gallery.setHorizontalFadingEdgeEnabled(false);
		gallery.setAdapter(new GalleryAdapter(this));
		gallery.setOnItemSelectedListener(this);
		gallery.setSelection(filenames.indexOf(filename));
		setContentView(gallery);
	}

	private void showInfo()
	{
		RECOIL recoil;
		try {
			recoil = decode(gallery.getSelectedItemPosition());
		}
		catch (RECOILException ex) {
			// whole screen already contains the error message
			return;
		}
		String message = getString(R.string.info_message, recoil.getPlatform(), recoil.getOriginalWidth(), recoil.getOriginalHeight(), recoil.getColors());
		new AlertDialog.Builder(this).setTitle(R.string.info_title).setMessage(message).show();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu)
	{
		if (gallery == null)
			return false;
		getMenuInflater().inflate(R.menu.viewer, menu);
		favoriteMenuItem = menu.findItem(R.id.menu_favorite);
		setFavoriteIcon(filenames.get(gallery.getSelectedItemPosition()));
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item)
	{
		switch (item.getItemId()) {
		case android.R.id.home:
			finish();
			return true;
		case R.id.menu_info:
			showInfo();
			return true;
		case R.id.menu_favorite:
			Uri uri = FileUtil.buildUri(baseUri, filenames.get(gallery.getSelectedItemPosition()));
			FileUtil.setFavoriteIcon(item, FileUtil.toggleFavorite(this, favorites, uri));
			return true;
		default:
			return false;
		}
	}
}
