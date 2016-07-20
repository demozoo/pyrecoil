/*
 * AndroidSupport.java - RECOIL for Android
 *
 * Copyright (C) 2016  Piotr Fusik
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
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Build;
import android.os.Environment;
import android.text.TextUtils;
import java.util.Arrays;
import java.util.Set;
import java.util.TreeSet;

class AndroidSupport
{
	static AndroidSupport getInstance()
	{
		int api = Build.VERSION.SDK_INT;
		if (api >= Build.VERSION_CODES.HONEYCOMB_MR1)
			return new Android12Support();
		if (api >= Build.VERSION_CODES.HONEYCOMB)
			return new Android11Support();
		if (api >= Build.VERSION_CODES.FROYO)
			return new Android8Support();
		return new AndroidSupport();
	}

	Uri getDownloadsDirectory()
	{
		return null;
	}

	Set<String> getStringSet(SharedPreferences preferences, String key, Set<String> defValues)
	{
		String value = preferences.getString(key, null);
		if (value == null)
			return defValues;
		return new TreeSet<String>(Arrays.asList(value.split("\\|")));
	}

	void putStringSet(SharedPreferences.Editor editor, String key, Set<String> values)
	{
		editor.putString(key, TextUtils.join("|", values));
	}

	void setDisplayHomeAsUpEnabled(Activity activity)
	{
	}

	void setHasAlpha(Bitmap bitmap, boolean hasAlpha)
	{
	}
}

class Android8Support extends AndroidSupport
{
	@Override
	Uri getDownloadsDirectory()
	{
		return Uri.fromFile(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS));
	}
}

class Android11Support extends Android8Support
{
	@Override
	Set<String> getStringSet(SharedPreferences preferences, String key, Set<String> defValues)
	{
		return preferences.getStringSet(key, defValues);
	}

	@Override
	void putStringSet(SharedPreferences.Editor editor, String key, Set<String> values)
	{
		editor.putStringSet(key, values);
	}

	@Override
	void setDisplayHomeAsUpEnabled(Activity activity)
	{
		activity.getActionBar().setDisplayHomeAsUpEnabled(true);
	}
}

class Android12Support extends Android11Support
{
	@Override
	void setHasAlpha(Bitmap bitmap, boolean hasAlpha)
	{
		bitmap.setHasAlpha(hasAlpha);
	}
}
