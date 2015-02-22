/*
 * Viewer.java - RECOIL for Android
 *
 * Copyright (C) 2013-2014  Piotr Fusik and Adrian Matoga
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
import android.widget.Toast;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.IOException;
import java.util.ArrayList;
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

	/**
	 * Reads bytes from the stream into the byte array
	 * until end of stream or array is full.
	 * @param is source stream
	 * @param b output array
	 * @return number of bytes read
	 */
	private static int readAndClose(InputStream is, byte[] b) throws IOException
	{
		int got = 0;
		int len = b.length;
		try {
			while (got < len) {
				int i = is.read(b, got, len - got);
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

	RECOIL decode(int position) throws RECOILException
	{
		Uri uri = FileUtil.buildUri(baseUri, filenames.get(position));

		// Read file
		byte[] content = new byte[RECOIL.MAX_CONTENT_LENGTH];
		int contentLength;
		String filename = uri.getPath();
		try {
			if (FileUtil.isZip(filename)) {
				ZipFile zip = new ZipFile(filename);
				try {
					filename = uri.getFragment();
					InputStream is = zip.getInputStream(zip.getEntry(filename));
					contentLength = readAndClose(is, content);
				}
				finally {
					zip.close();
				}
			}
			else {
				InputStream is = new FileInputStream(filename);
				contentLength = readAndClose(is, content);
			}
		}
		catch (IOException ex) {
			throw new RECOILException(getString(R.string.error_reading_file, filename));
		}

		// Decode
		RECOIL recoil = new RECOIL();
		if (!recoil.decode(filename, content, contentLength))
			throw new RECOILException(getString(R.string.error_decoding_file, filename));
		return recoil;
	}

	public void onItemSelected(AdapterView<?> parent, View view, int position, long id)
	{
		setTitle(getString(R.string.viewing_title, filenames.get(position)));
	}

	public void onNothingSelected(AdapterView<?> parent)
	{
		// can we ever get here?
	}

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);

		Uri uri = getIntent().getData();
		String filename = split(uri);
		try {
			filenames = FileUtil.list(baseUri, null);
		}
		catch (IOException ex) {
			Toast.makeText(this, R.string.error_listing_files, Toast.LENGTH_SHORT).show();
			return;
		}

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
		getMenuInflater().inflate(R.menu.viewer, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item)
	{
		switch (item.getItemId()) {
		case R.id.menu_info:
			showInfo();
			return true;
		case R.id.menu_about:
			About.show(this);
			return true;
		default:
			return false;
		}
	}
}
