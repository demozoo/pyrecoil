/*
 * FileSelector.java - RECOIL for Android
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

package net.sf.recoil;

import android.app.ListActivity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import java.io.IOException;
import java.util.ArrayList;
import java.util.TreeSet;

public class FileSelector extends ListActivity
{
	private Uri uri;
	private boolean isSearch;

	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		ListView listView = getListView();
		listView.setTextFilterEnabled(true);
		uri = getIntent().getData();
		if (uri == null)
			uri = FileUtil.getRootDirectory();

		AndroidSupport.getInstance().setDisplayHomeAsUpEnabled(this);
		setTitle(getString(R.string.selector_title, FileUtil.getDisplayName(uri)));

		ArrayList<String> files;
		TreeSet<String> directories = new TreeSet<String>(FileUtil.getComparator());
		int emptyViewId;
		try {
			files = FileUtil.list(uri, directories);
			files.addAll(0, directories);
			emptyViewId = R.layout.no_files;
		}
		catch (IOException ex) {
			files = new ArrayList<String>();
			emptyViewId = R.layout.access_denied;
		}
		View emptyView = getLayoutInflater().inflate(emptyViewId, null);
		((ViewGroup) listView.getParent()).addView(emptyView);
		listView.setEmptyView(emptyView);
		setListAdapter(new ArrayAdapter<String>(this, R.layout.filename_list_item, files));
	}

	@Override
	protected void onListItemClick(ListView l, View v, int position, long id)
	{
		String name = (String) l.getItemAtPosition(position);
		Class klass = RECOIL.isOurFile(name) ? Viewer.class : FileSelector.class;
		Intent intent = new Intent(Intent.ACTION_VIEW, FileUtil.buildUri(uri, name), this, klass);
		startActivity(intent);
	}

	private boolean isBuiltinFavorite()
	{
		return uri.equals(FileUtil.getRootDirectory())
			|| uri.equals(AndroidSupport.getInstance().getDownloadsDirectory());
	}

	private boolean isUserFavorite()
	{
		return FileUtil.getUserFavorites(this).contains(uri.toString());
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu)
	{
		getMenuInflater().inflate(R.menu.file_selector, menu);
		MenuItem favoriteMenuItem = menu.findItem(R.id.menu_favorite);
		if (isBuiltinFavorite())
			favoriteMenuItem.setVisible(false);
		else
			FileUtil.setFavoriteIcon(favoriteMenuItem, isUserFavorite());
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item)
	{
		switch (item.getItemId()) {
		case android.R.id.home:
			finish();
			return true;
		case R.id.menu_search:
			InputMethodManager imm = (InputMethodManager) getSystemService(INPUT_METHOD_SERVICE);
			if (isSearch) {
				imm.hideSoftInputFromWindow(getListView().getWindowToken(), 0);
				getListView().clearTextFilter();
				isSearch = false;
			}
			else {
				imm.showSoftInput(getListView(), 0);
				isSearch = true;
			}
			return true;
		case R.id.menu_favorite:
			FileUtil.setFavoriteIcon(item, FileUtil.toggleFavorite(this, new TreeSet(FileUtil.getUserFavorites(this)), uri));
			return true;
		default:
			return false;
		}
	}
}
