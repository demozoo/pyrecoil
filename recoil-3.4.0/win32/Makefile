VERSION = 3.4.0

CITO = cito
XSLTPROC = xsltproc -o $@
RECOIL_CC = mingw32-gcc -s -O2 -Wall -o $@ -I..
RECOIL_CC_DLL = $(RECOIL_CC) -shared -Wl,--kill-at -Wl,-subsystem,windows
RECOIL_GPP = mingw32-g++ -static -s -O2 -Wall -o $@ -I..
WINDRES = windres -o $@
X64_RECOIL_CC = x86_64-w64-mingw32-gcc -s -O2 -Wall -o $@ -I..
X64_RECOIL_CC_DLL = $(X64_RECOIL_CC) -shared -Wl,--kill-at -Wl,-subsystem,windows
X64_RECOIL_GPP = x86_64-w64-mingw32-g++ -static -s -O2 -Wall -o $@ -I..
X64_WINDRES = x86_64-w64-mingw32-windres -o $@
CSC = C:/Windows/Microsoft.NET/Framework/v3.5/csc.exe -nologo -o+ -out:$@
RM = rm -f
UNIX2DOS = unix2dos
GIT = git
TAR = tar
SEVENZIP = 7z a -mx=9 -bd
CANDLE = candle -ext WixUtilExtension -nologo -o $@
LIGHT = light -ext WixUtilExtension -nologo -o $@ -spdb
IMAGEMAGICK_X64_INST_DIR = c:\Program Files\ImageMagick-6.8.9-Q16
PAINT_NET_DIR = c:\Program Files\Paint.NET

WIN32_BIN = recoil2png.exe IM_MOD_RL_recoil_.dll Xrecoil.usr recoilwin.exe RECOIL.plg RecoilPaintDotNet.dll

all: $(WIN32_BIN) thumbrecoil.dll

recoil2png.exe: ../recoil2png.c ../pngsave.c ../pngsave.h ../recoil-stdio.c ../recoil-stdio.h ../recoil.c ../recoil.h
	$(RECOIL_CC) ../recoil2png.c ../pngsave.c ../recoil-stdio.c ../recoil.c -static -lpng -lz

IM_MOD_RL_recoil_.dll: ../imagemagick/recoilmagick.c ../formats.h ../recoil.c ../recoil.h
	$(RECOIL_CC_DLL) ../imagemagick/recoilmagick.c ../recoil.c -lCORE_RL_magick_
 
x64/IM_MOD_RL_recoil_.dll: ../imagemagick/recoilmagick.c ../formats.h ../recoil.c ../recoil.h
	test -d x64 || mkdir x64
	$(X64_RECOIL_CC_DLL) ../imagemagick/recoilmagick.c ../recoil.c -I"$(IMAGEMAGICK_X64_INST_DIR)"/include -lCORE_RL_magick_ -L"$(IMAGEMAGICK_X64_INST_DIR)"

Xrecoil.usr: xnview/Xrecoil.c ../formats.h recoil-win32.c recoil-win32.h ../recoil.c ../recoil.h
	$(RECOIL_CC_DLL) -I. xnview/Xrecoil.c recoil-win32.c ../recoil.c

recoilwin.exe: recoilwin/recoilwin.c recoilwin/recoilwin.h recoil-win32.c recoil-win32.h recoilwin/recoilwin-res.o ../pngsave.c ../pngsave.h ../formats.h ../recoil.c ../recoil.h
	$(RECOIL_CC) -I. -Wl,-subsystem,windows recoilwin/recoilwin.c recoil-win32.c recoilwin/recoilwin-res.o ../pngsave.c ../recoil.c -lcomctl32 -lcomdlg32 -lgdi32 -static -lpng -lz

recoilwin/recoilwin-res.o: recoilwin/recoilwin.rc recoilwin/recoilwin.h recoil.ico ../recoil.h
	$(WINDRES) -I .. recoilwin/recoilwin.rc

thumbrecoil.dll: thumbrecoil/thumbrecoil.cpp ../formats.h recoil-win32.c recoil-win32.h ../recoil.c ../recoil.h
	$(RECOIL_GPP) -I. -shared -Wl,-subsystem,windows -Wl,--kill-at thumbrecoil/thumbrecoil.cpp recoil-win32.c ../recoil.c -lgdi32 -lole32 -luuid

x64/thumbrecoil.dll: thumbrecoil/thumbrecoil.cpp ../formats.h recoil-win32.c recoil-win32.h ../recoil.c ../recoil.h
	test -d x64 || mkdir x64
	$(X64_RECOIL_GPP) -I. -shared -Wl,-subsystem,windows -Wl,--kill-at thumbrecoil/thumbrecoil.cpp recoil-win32.c ../recoil.c -lgdi32 -lole32 -luuid

RECOIL.plg: imagine/recoilimagine.c ../formats.h ../recoil.c ../recoil.h
	$(RECOIL_CC_DLL) imagine/recoilimagine.c ../recoil.c

x64/RECOIL.plg64: imagine/recoilimagine.c ../formats.h ../recoil.c ../recoil.h
	test -d x64 || mkdir x64
	$(X64_RECOIL_CC_DLL) imagine/recoilimagine.c ../recoil.c

RecoilPaintDotNet.dll: paint.net/RecoilPaintDotNet.cs paint.net/RecoilFileTypeFactory.cs paint.net/RECOIL.cs
	$(CSC) -t:library paint.net\\RecoilPaintDotNet.cs paint.net\\RecoilFileTypeFactory.cs paint.net\\RECOIL.cs -r:"$(PAINT_NET_DIR)\PaintDotNet.Base.dll" -r:"$(PAINT_NET_DIR)\PaintDotNet.Data.dll"

paint.net/RecoilFileTypeFactory.cs: paint.net/RecoilFileTypeFactory.cs.xsl ../formats.xml
	$(XSLTPROC) paint.net/RecoilFileTypeFactory.cs.xsl ../formats.xml

paint.net/RECOIL.cs: ../recoil.ci ../atari8.fnt ../altirrapal.pal ../c16.pal ../zx81.fnt
	$(CITO) -o $@ -I .. -n Recoil $<

../formats.h: ../formats.h.xsl ../formats.xml
	$(XSLTPROC) ../formats.h.xsl ../formats.xml

# http://www.cmcrossroads.com/article/rules-multiple-outputs-gnu-make
%.c %.h: %.ci ../atari8.fnt ../altirrapal.pal ../c16.pal ../zx81.fnt
	$(CITO) -o $*.c -I .. $<

recoil.ico: ../recoil-512x512.png
	convert $< -resize 48x48 $@

COPYING.txt: ../COPYING
	$(UNIX2DOS) <$< >$@

setup: ../../recoil-$(VERSION)-win32.msi

../../recoil-$(VERSION)-win32.msi: setup/recoil.wixobj recoil.ico setup/dialog.jpg setup/banner.jpg setup/license.rtf $(WIN32_BIN) thumbrecoil.dll
	$(LIGHT) -ext WixUIExtension -sice:ICE69 $<

setup/recoil.wixobj: setup/recoil.wxs setup/formats.wxi
	$(CANDLE) -dVERSION=$(VERSION) $<

setup/formats.wxi: setup/formats.wxi.xsl ../formats.xml
	$(XSLTPROC) setup/formats.wxi.xsl ../formats.xml

setup/dialog.jpg: ../recoil-512x512.png
	convert $< -resize 148 -extent 493x312-16-82 -strip $@

setup/banner.jpg: ../recoil-512x512.png
	convert $< -resize 48 -extent 493x58-425-5 -strip $@

x64-setup: ../../recoil-$(VERSION)-win64.msi

../../recoil-$(VERSION)-win64.msi: x64/recoil.wixobj recoil.ico setup/dialog.jpg setup/banner.jpg setup/license.rtf $(WIN32_BIN) thumbrecoil.dll x64/thumbrecoil.dll x64/IM_MOD_RL_recoil_.dll x64/RECOIL.plg64
	$(LIGHT) -ext WixUIExtension -sice:ICE69 -sice:ICE80 -b setup $<

x64/recoil.wixobj: setup/recoil.wxs setup/formats.wxi
	test -d x64 || mkdir x64
	$(CANDLE) -arch x64 -dVERSION=$(VERSION) $<

../MANIFEST:
	test -e ../.git && ( \
		($(GIT) --git-dir=../.git ls-files | grep -vF .gitignore \
			&& echo MANIFEST && echo recoil.c && echo recoil.h) | sort >$@; \
	)

srcdist: ../MANIFEST ../recoil.c ../recoil.h
	$(RM) ../../recoil-$(VERSION).tar.gz
	cd .. && $(TAR) -c --numeric-owner --owner=0 --group=0 --mode=644 -T MANIFEST --transform=s,,recoil-$(VERSION)/, | $(SEVENZIP) -tgzip -si ../recoil-$(VERSION).tar.gz

dist: srcdist ../../recoil-$(VERSION)-win32.zip setup x64-setup

../../recoil-$(VERSION)-win32.zip: COPYING.txt $(WIN32_BIN)
	$(RM) ../../recoil-$(VERSION)-win32.zip
	$(SEVENZIP) -tzip ../../recoil-$(VERSION)-win32.zip COPYING.txt $(WIN32_BIN)

clean:
	$(RM) $(WIN32_BIN) thumbrecoil.dll recoilwin/recoilwin-res.o recoil.ico COPYING.txt \
		setup/formats.wxi setup/recoil.wixobj setup/dialog.jpg setup/banner.jpg x64/recoil.wixobj \
		x64/IM_MOD_RL_recoil_.dll x64/thumbrecoil.dll x64/RECOIL.plg64 RecoilPaintDotNet.dll \
		paint.net/RecoilFileTypeFactory.cs paint.net/RECOIL.cs ../formats.h

.PHONY: all clean setup x64-setup ../MANIFEST srcdist dist www

.DELETE_ON_ERROR:
