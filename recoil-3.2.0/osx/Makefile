VERSION = 3.2.0

BINARY = bin/RECOIL.qlgenerator/Contents/MacOS/qlrecoil 
PLIST = bin/RECOIL.qlgenerator/Contents/Info.plist

recoil-$(VERSION)-osx.dmg: bin/QuickLook $(BINARY) $(PLIST)
	hdiutil create -volname recoil-$(VERSION)-osx -srcfolder bin -format UDBZ -imagekey bzip2-level=3 -ov $@

bin/QuickLook:
	mkdir -p $(@D) && ln -s /Library/QuickLook $@

$(BINARY): qlrecoil.c ../recoil.c ../recoil.h
# As of Xcode 4.6.3, -O2 gives RECOIL_Decode a 2.5MB stack, which causes non-deterministic bus errors :(
	mkdir -p $(@D) && gcc -O1 -Wall -o $@ -I .. -dynamiclib -arch x86_64 -arch i386 -mmacosx-version-min=10.5 qlrecoil.c ../recoil.c -framework QuickLook -framework ApplicationServices -framework CoreFoundation && strip -x $@

$(PLIST): Info.plist.xsl ../formats.xml
	mkdir -p $(@D) && xsltproc -o $@ Info.plist.xsl ../formats.xml

%.c %.h: %.ci ../atari8.fnt ../altirrapal.pal ../c16.pal ../zx81.fnt
	cito -o $*.c -I .. $<

clean:
	rm -rf recoil-$(VERSION)-osx.dmg bin

.PHONY: clean

.DELETE_ON_ERROR:
