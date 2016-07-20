<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="xml" indent="yes" doctype-public="-//Apple//DTD PLIST 1.0//EN" doctype-system="http://www.apple.com/DTDs/PropertyList-1.0.dtd" />
	<xsl:template match="/formats">
		<xsl:comment>Generated automatically from formats.xml and Info.plist.xsl. Do not edit.</xsl:comment>
		<plist version="1.0">
			<dict>
				<key>CFBundleDevelopmentRegion</key>
				<string>English</string>
				<key>CFBundleDocumentTypes</key>
				<array>
					<dict>
						<key>CFBundleTypeRole</key>
						<string>QLGenerator</string>
						<key>LSItemContentTypes</key>
						<array>
							<xsl:for-each select="platform/format/ext[not(. = ../following-sibling::format/ext)]">
								<string>
									<xsl:value-of select="translate(../../@name, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ-/ ','abcdefghijklmnopqrstuvwxyz')" />.<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
								</string>
							</xsl:for-each>
						</array>
					</dict>
				</array>
				<key>CFBundleExecutable</key>
				<string>qlrecoil</string>
				<key>CFBundleIconFile</key>
				<string></string>
				<key>CFBundleIdentifier</key>
				<string>net.sf.recoil.qlrecoil</string>
				<key>CFBundleInfoDictionaryVersion</key>
				<string>6.0</string>
				<key>CFBundleName</key>
				<string>qlrecoil</string>
				<key>CFBundleShortVersionString</key>
				<string>1</string>
				<key>CFBundleVersion</key>
				<string>1.0</string>
				<key>CFPlugInDynamicRegisterFunction</key>
				<string></string>
				<key>CFPlugInDynamicRegistration</key>
				<string>NO</string>
				<key>CFPlugInFactories</key>
				<dict>
					<key>B4EBAF99-E681-49A5-91CA-78459C948EEA</key>
					<string>QuickLookGeneratorPluginFactory</string>
				</dict>
				<key>CFPlugInTypes</key>
				<dict>
					<key>5E2D9680-5022-40FA-B806-43349622E5B9</key>
					<array>
						<string>B4EBAF99-E681-49A5-91CA-78459C948EEA</string>
					</array>
				</dict>
				<key>CFPlugInUnloadFunction</key>
				<string></string>
				<key>NSHumanReadableCopyright</key>
				<string>Copyright © 2014-2016 Piotr Fusik, Adrian Matoga, Petri Pyy. All rights reserved.</string>
				<key>QLNeedsToBeRunInMainThread</key>
				<false/>
				<key>QLPreviewHeight</key>
				<real>600</real>
				<key>QLPreviewWidth</key>
				<real>800</real>
				<key>QLSupportsConcurrentRequests</key>
				<true/>
				<key>QLThumbnailMinimumSize</key>
				<real>17</real>
				<key>UTImportedTypeDeclarations</key>
				<array>
					<xsl:for-each select="platform/format/ext[not(. = ../following-sibling::format/ext)]">
						<xsl:variable name="ext" select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
						<dict>
							<key>UTTypeConformsTo</key>
							<array>
								<string>public.image</string>
							</array>
							<key>UTTypeDescription</key>
							<string><xsl:value-of select="../../@name" /><xsl:text> </xsl:text><xsl:value-of select="../@name" /></string>
							<key>UTTypeIdentifier</key>
							<string><xsl:value-of select="translate(../../@name, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ-/ ','abcdefghijklmnopqrstuvwxyz')" />.<xsl:value-of select="$ext" /></string>
							<key>UTTypeTagSpecification</key>
							<dict>
								<key>public.filename-extension</key>
								<array>
									<string><xsl:value-of select="$ext" /></string>
								</array>
								<key>public.mime-type</key>
								<array>
									<string>application/x-<xsl:value-of select="$ext" /></string>
									<string>image/<xsl:value-of select="$ext" /></string>
									<string>image/x-<xsl:value-of select="$ext" /></string>
								</array>
							</dict>
						</dict>
					</xsl:for-each>
				</array>
			</dict>
		</plist>
	</xsl:template>
</xsl:stylesheet>
