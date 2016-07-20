<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="text" />
	<xsl:template match="/formats">
		<xsl:text>/* Generated automatically from formats.xml and formats.h.xsl. Do not edit. */&#10;&#10;</xsl:text>
		<xsl:text>#define IMAGINE_RECOIL_EXTS</xsl:text>
		<xsl:for-each select="platform/format/ext[not(. = following::ext)]">
			<xsl:sort />
			<xsl:text> "</xsl:text>
			<xsl:value-of select="." />
			<xsl:text>\0"</xsl:text>
		</xsl:for-each>
		<xsl:text>&#10;&#10;</xsl:text>

		<xsl:text>#define XNVIEW_RECOIL_EXTS "</xsl:text>
		<xsl:for-each select="platform/format/ext[not(. = following::ext)]">
			<xsl:sort />
			<xsl:if test="position() != 1">;</xsl:if>
			<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
		</xsl:for-each>
		<xsl:text>"&#10;&#10;</xsl:text>

		<xsl:text>#define THUMBRECOIL_EXTS </xsl:text>
		<xsl:for-each select="platform/format/ext[not(. = following::ext)]">
			<xsl:sort />
			<xsl:if test="position() != 1">
				<xsl:text>, </xsl:text>
			</xsl:if>
			<xsl:text>".</xsl:text>
			<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
			<xsl:text>"</xsl:text>
		</xsl:for-each>
		<xsl:text>&#10;&#10;</xsl:text>

		<xsl:text>#define RECOILWIN_FILTERS "All supported\0</xsl:text>
		<xsl:for-each select="platform/format/ext[not(. = following::ext)]">
			<xsl:sort />
			<xsl:if test="position() != 1">;</xsl:if>
			<xsl:text>*.</xsl:text>
			<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
		</xsl:for-each>
		<xsl:text>\0" \&#10;</xsl:text>
		<xsl:for-each select="platform">
			<xsl:text>&#9;"</xsl:text>
			<xsl:value-of select="@name" />
			<xsl:text>\0</xsl:text>
			<xsl:for-each select="format/ext[not(. = ../following-sibling::format/ext)]">
				<xsl:sort />
				<xsl:if test="position() != 1">;</xsl:if>
				<xsl:text>*.</xsl:text>
				<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
			</xsl:for-each>
			<xsl:text>\0" \&#10;</xsl:text>
		</xsl:for-each>
		<xsl:text>&#9;"\0"&#10;&#10;</xsl:text>

		<xsl:text>#define MAGICK_RECOIL_FORMATS </xsl:text>
		<xsl:for-each select="platform/format/ext[not(../companionExt)][not(. = following::ext)]">
			<xsl:sort />
			<xsl:if test="position() != 1">
				<xsl:text>, \&#10;&#9;</xsl:text>
			</xsl:if>
			<xsl:text>{ "</xsl:text>
			<xsl:value-of select="." />
			<xsl:text>", "</xsl:text>
			<xsl:variable name="ext" select="." />
			<xsl:for-each select="../../../platform[format/ext = $ext]">
				<xsl:if test="position() != 1">
					<xsl:text> or </xsl:text>
				</xsl:if>
				<xsl:value-of select="@name" />
			</xsl:for-each>
			<xsl:text>" }</xsl:text>
		</xsl:for-each>
		<xsl:text>&#10;&#10;</xsl:text>
	</xsl:template>
</xsl:stylesheet>
