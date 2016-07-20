<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="xml" indent="yes" />
	<xsl:template match="/formats">
		<xsl:comment>Generated automatically from formats.xml and formats.wxi.xsl. Do not edit.</xsl:comment>
		<Include>
			<xsl:processing-instruction name="define">
				<xsl:text>FIRST_EXT=</xsl:text>
				<xsl:for-each select="platform/format/ext">
					<xsl:sort />
					<xsl:if test="position() = 1">
						<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
					</xsl:if>
				</xsl:for-each>
			</xsl:processing-instruction>
			<xsl:processing-instruction name="define">
				<xsl:text>OTHER_EXTS=</xsl:text>
					<xsl:for-each select="platform/format/ext[not(. = following::ext)]">
						<xsl:sort />
						<xsl:if test="position() != 1">
							<xsl:if test="position() != 2">;</xsl:if>
							<xsl:value-of select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')" />
						</xsl:if>
					</xsl:for-each>
			</xsl:processing-instruction>
		</Include>
	</xsl:template>
</xsl:stylesheet>
