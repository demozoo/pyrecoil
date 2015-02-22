all: recoil.js html5recoil.html

recoil.js: ../recoil.ci ../atari8.fnt ../altirrapal.pal ../c16.pal ../zx81.fnt
	cito -o $@ -I .. $<

html5recoil.html: html5recoil.txt
	asciidoc -o - $< | sed -e "s/527bbd;/800080;/" > $@

clean:
	$(RM) recoil.js html5recoil.html

.PHONY: all clean

.DELETE_ON_ERROR:
