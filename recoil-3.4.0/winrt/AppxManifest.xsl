<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="xml" indent="yes" />
	<xsl:template match="/formats">
		<xsl:comment>Generated automatically from formats.xml and AppxManifest.xsl. Do not edit.</xsl:comment>
		<Package xmlns="http://schemas.microsoft.com/appx/2010/manifest">
			<Identity Name="RECOIL" Publisher="CN=foxoft.com.pl" Version="3.4.0.0" />
			<Properties>
				<DisplayName>RECOIL</DisplayName>
				<PublisherDisplayName>Piotr Fusik</PublisherDisplayName>
				<Logo>Logo.png</Logo>
				<Description>RECOIL (Retro Computer Image Library) is a viewer of pictures in native formats of classic home computers: Amiga, Amstrad CPC, Apple II, Atari 8-bit, Atari Portfolio, Atari ST, Atari Falcon, BBC Micro, Commodore 16, Commodore 64, Commodore 128, Macintosh 128K, MSX, Oric, SAM Coupé, TRS-80, ZX81 and ZX Spectrum.</Description>
			</Properties>
			<Prerequisites>
				<OSMinVersion>6.2</OSMinVersion>
				<OSMaxVersionTested>6.2</OSMaxVersionTested>
			</Prerequisites>
			<Resources>
				<Resource Language="en-us" />
			</Resources>
			<Applications>
				<Application Id="MetroRECOIL" Executable="MetroRECOIL.exe" EntryPoint="MetroRECOIL">
					<VisualElements DisplayName="RECOIL" Description="Shows images in native formats of classic computers"
						Logo="Logo.png" SmallLogo="SmallLogo.png" BackgroundColor="#800080" ForegroundText="light">
						<DefaultTile ShowName="allLogos" />
						<SplashScreen Image="SplashScreen.png" />
					</VisualElements>
					<Extensions>
						<Extension Category="windows.fileTypeAssociation">
							<FileTypeAssociation Name="recoil">
								<Logo>FileLogo.png</Logo>
								<SupportedFileTypes>
									<xsl:for-each select="platform/format/ext[not(. = following::ext) and . != 'SCR']"><!-- the '.scr' file type association is reserved for system use -->
										<xsl:sort />
										<FileType>.<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" /></FileType>
									</xsl:for-each>
								</SupportedFileTypes>
							</FileTypeAssociation>
						</Extension>
					</Extensions>
				</Application>
			</Applications>
		</Package>
	</xsl:template>
</xsl:stylesheet>
