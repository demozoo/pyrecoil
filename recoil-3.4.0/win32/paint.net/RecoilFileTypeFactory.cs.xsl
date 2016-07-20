<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="text" />
	<xsl:template match="/formats">
		<xsl:text>// Generated automatically from formats.xml and RecoilFileTypeFactory.cs.xsl. Do not edit.

using PaintDotNet;

namespace Recoil.PaintDotNet
{
	public class RecoilFileTypeFactory : IFileTypeFactory
	{
		public FileType[] GetFileTypeInstances()
		{
			return new FileType[] {
</xsl:text>
		<xsl:for-each select="platform/format/ext[not(../companionExt)][not(. = following::ext)]">
			<xsl:sort />
			<xsl:if test="position() != 1">
				<xsl:text>,&#10;</xsl:text>
			</xsl:if>
			<xsl:text>&#9;&#9;&#9;&#9;new RecoilFileType(".</xsl:text>
			<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
			<xsl:text>", "</xsl:text>
			<xsl:variable name="ext" select="." />
			<xsl:for-each select="../../../platform[format/ext = $ext]">
				<xsl:if test="position() != 1">
					<xsl:text> or </xsl:text>
				</xsl:if>
				<xsl:value-of select="@name" />
			</xsl:for-each>
			<xsl:text>")</xsl:text>
		</xsl:for-each>
		<xsl:text>
			};
		}
	}
}
</xsl:text>
	</xsl:template>
</xsl:stylesheet>
