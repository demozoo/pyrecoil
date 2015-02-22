<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="xml" indent="yes" />
	<xsl:template match="/formats">
		<xsl:comment>Generated automatically from formats.xml and AndroidManifest.xsl. Do not edit.</xsl:comment>
		<manifest xmlns:android="http://schemas.android.com/apk/res/android"
			package="net.sf.recoil" android:versionCode="320" android:versionName="3.2.0" android:installLocation="auto">
			<uses-sdk android:minSdkVersion="4" android:targetSdkVersion="19" />
			<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
			<supports-screens android:largeScreens="true" android:xlargeScreens="true" />
			<application android:label="@string/app_name" android:icon="@drawable/ic_launcher" android:description="@string/app_description">
				<activity android:name=".FileSelector" android:label="@string/app_name">
					<intent-filter>
						<action android:name="android.intent.action.MAIN" />
						<category android:name="android.intent.category.LAUNCHER" />
					</intent-filter>
				</activity>
				<activity android:name=".Viewer" android:label="@string/view_in_recoil" android:launchMode="singleTop" android:configChanges="mcc|mnc|keyboard|keyboardHidden|orientation|screenSize">
					<intent-filter>
						<action android:name="android.intent.action.VIEW" />
						<category android:name="android.intent.category.DEFAULT" />
						<category android:name="android.intent.category.BROWSABLE" />
						<data android:mimeType="*/*" />
						<data android:scheme="file" android:host="*" />
						<xsl:for-each select="platform/format/ext[not(. = following::ext)]">
							<xsl:sort />
							<data android:pathPattern=".*\\.{translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')}" />
						</xsl:for-each>
					</intent-filter>
				</activity>
			</application>
		</manifest>
	</xsl:template>
</xsl:stylesheet>
