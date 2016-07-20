/*
 * FavoriteSelector.java - RECOIL for Android
 *
 * Copyright (C) 2015-2016  Piotr Fusik
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
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Set;

class FavoriteUri
{
	private final String displayName;
	private final Uri uri;

	FavoriteUri(String displayName, Uri uri)
	{
		this.displayName = displayName;
		this.uri = uri;
	}

	@Override
	public String toString()
	{
		return displayName;
	}

	public Uri getUri()
	{
		return uri;
	}
}

public class FavoriteSelector extends ListActivity
{
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		getListView().setTextFilterEnabled(true);
		setListAdapter(new ArrayAdapter<FavoriteUri>(this, R.layout.filename_list_item));
	}

	@Override
	protected void onStart()
	{
		super.onStart();
		ArrayAdapter<FavoriteUri> adapter = (ArrayAdapter<FavoriteUri>) getListAdapter();
		adapter.clear();
		adapter.add(new FavoriteUri(getString(R.string.root_directory), FileUtil.getRootDirectory()));
		Uri uri = AndroidSupport.getInstance().getDownloadsDirectory();
		if (uri != null)
			adapter.add(new FavoriteUri(getString(R.string.downloads_directory), uri));

		Set<String> userFavoritesSet = FileUtil.getUserFavorites(this);
		String[] userFavorites = userFavoritesSet.toArray(new String[userFavoritesSet.size()]);
		Arrays.sort(userFavorites);
		for (String s : userFavorites) {
			uri = Uri.parse(s);
			adapter.add(new FavoriteUri(FileUtil.getDisplayName(uri), uri));
		}
	}

	@Override
	protected void onListItemClick(ListView l, View v, int position, long id)
	{
		FavoriteUri favorite = (FavoriteUri) l.getItemAtPosition(position);
		Uri uri = favorite.getUri();
		Class klass = RECOIL.isOurFile(uri.toString()) ? Viewer.class : FileSelector.class;
		Intent intent = new Intent(Intent.ACTION_VIEW, uri, this, klass);
		startActivity(intent);
	}
}
