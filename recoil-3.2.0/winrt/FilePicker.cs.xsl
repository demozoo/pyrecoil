<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="text" />
	<xsl:template match="/formats">
		<xsl:text>// Generated automatically from formats.xml and FilePicker.cs.xsl. Do not edit.

using Windows.Foundation;
using Windows.Storage;
using Windows.Storage.Pickers;

public static class FilePicker
{
	public static IAsyncOperation&lt;StorageFile&gt; PickFile()
	{
		FileOpenPicker fop = new FileOpenPicker {
			FileTypeFilter = { </xsl:text>
			<xsl:for-each select="platform/format/ext[not(. = following::ext)]">
				<xsl:sort />
				<xsl:if test="position() != 1">, </xsl:if>
				<xsl:text>".</xsl:text>
				<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
				<xsl:text>"</xsl:text>
			</xsl:for-each>
		<xsl:text> },
			SuggestedStartLocation = PickerLocationId.ComputerFolder // Downloads, Desktop?
		};
		return fop.PickSingleFileAsync();
	}
}
</xsl:text>
	</xsl:template>
</xsl:stylesheet>
