all: index.html formats.html html5recoil.html news.html contact.html recoil.js

index.html: www.xsl index.xml
	xsltproc --stringparam title Home $^ | xmllint --valid --nonet -o $@ -

formats.html: www.xsl ../formats.xml
	xsltproc --stringparam title Formats $^ | xmllint --valid --nonet -o $@ -

news.html: www.xsl news.xml
	xsltproc --stringparam title News $^ | xmllint --valid --nonet -o $@ -

contact.html: www.xsl contact.xml
	xsltproc --stringparam title Contact $^ | xmllint --valid --nonet -o $@ -

html5recoil.html: www.xsl html5recoil.xml
	xsltproc --stringparam title HTML5 $^ \
		| grep -v '^<!DOCTYPE ' \
		| xmllint --schema /etc/xml/xhtml5.xsd --nonet -o $@ -

recoil.js: ../recoil.ci ../atari8.fnt ../altirrapal.pal ../c16.pal ../zx81.fnt
	cito -o $@ -l js-ta -I .. $<

clean:
	$(RM) index.html formats.html html5recoil.html news.html contact.html recoil.js

.PHONY: all clean

.DELETE_ON_ERROR:
