PREFIX = /usr/local
MAGICK_VERSION     := $(shell MagickCore-config --version 2>/dev/null)
ifdef MAGICK_VERSION
MAGICK_CFLAGS      := $(shell MagickCore-config --cflags --cppflags) -fPIC
MAGICK_LDFLAGS     := $(shell MagickCore-config --ldflags)
MAGICK_LIBS        := $(shell MagickCore-config --libs)
MAGICK_PREFIX      := $(shell MagickCore-config --prefix)
MAGICK_CODER_PATH  := $(wildcard $(MAGICK_PREFIX)/lib/ImageMagick-$(word 1,$(MAGICK_VERSION))/modules-$(word 2,$(MAGICK_VERSION))/coders)
MAGICK_CONFIG_PATH := $(wildcard $(shell MagickCore-config --exec-prefix)/etc/ImageMagick)
CAN_INSTALL_MAGICK := $(and $(MAGICK_CODER_PATH),$(MAGICK_CONFIG_PATH))
endif

CITO = cito
CC = gcc 
CFLAGS = -s -O2 -Wall
INSTALL = install
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644

FORMATS    = GR8 HIP MIC INT TIP INP HR GR9 PIC CPR CIN CCI APC PLM AP3 ILC RIP FNT SXS MCP GHG HR2 MCH IGE 256 AP2 JGP DGP ESC PZM IST RAW RGB MGP WND CHR SHP MBG FWA RM0 RM1 RM2 RM3 RM4 XLP MAX SHC ALL APP SGE DLM BKG G09 BG9 APV SPC APL GR7 G10 G11 ART DRG AGP PLA MIS 4PL 4MI 4PM PGF PGC PI1 PI2 PI3 PC1 PC2 PC3 NEO DOO SPU TNY TN1 TN2 TN3 CA1 CA2 CA3 ING PAC SPS GFB PI4 PI9 DGU DG1 TRP TRU GOD FTC DEL DPH IPC NLQ PMD ACS PCS HPM MCS A4R DC1 DGC CPT IFF BL1 BL2 BL3 BRU IP2 IMN ICN DIN VZI IRG IR2 ICE IMG XIMG MPP SCR MC MG1 MG2 MG4 MG8 ATR IFL CH4 CH6 CH8 LEO ACBM ZXP HLR LBM CDU CHE CWG DD DOL DRZ FGS FPT GCD GIG GIH HBM HED HIR IPH IPT ISM KOA MIL MON OCP P64 PI PMG RP RPM SAR VID SIF DRL MCI AMI GG JJ 64C AFL BFLI BML DLP DRP ECI FFLI FLI FP2 FUN GUN HFC ECP DGI LUM BGP HPC AAS HLF HIM LP3 IHE HAM6 HAM8 3 MAC SCS4 4BT SC8 SR8 SC2 GRP FD2 VIC MLE RYS SCC SRS SCA HGB P4I INFO DUO PL4 P HCI MCPP DU1 DU2 BB0 BB1 BB2 BB4 BB5 BBG EPA MSP HGR DHR SHR A64 WIG
FORMATS_LC = gr8 hip mic int tip inp hr gr9 pic cpr cin cci apc plm ap3 ilc rip fnt sxs mcp ghg hr2 mch ige 256 ap2 jgp dgp esc pzm ist raw rgb mgp wnd chr shp mbg fwa rm0 rm1 rm2 rm3 rm4 xlp max shc all app sge dlm bkg g09 bg9 apv spc apl gr7 g10 g11 art drg agp pla mis 4pl 4mi 4pm pgf pgc pi1 pi2 pi3 pc1 pc2 pc3 neo doo spu tny tn1 tn2 tn3 ca1 ca2 ca3 ing pac sps gfb pi4 pi9 dgu dg1 trp tru god ftc del dph ipc nlq pmd acs pcs hpm mcs a4r dc1 dgc cpt iff bl1 bl2 bl3 bru ip2 imn icn din vzi irg ir2 ice img ximg mpp scr mc mg1 mg2 mg4 mg8 atr ifl ch4 ch6 ch8 leo acbm zxp hlr lbm cdu che cwg dd dol drz fgs fpt gcd gig gih hbm hed hir iph ipt ism koa mil mon ocp p64 pi pmg rp rpm sar vid sif drl mci ami gg jj 64c afl bfli bml dlp drp eci ffli fli fp2 fun gun hfc ecp dgi lum bgp hpc aas hlf him lp3 ihe ham6 ham8 3 mac scs4 4bt sc8 sr8 sc2 grp fd2 vic mle rys scc srs sca hgb p4i info duo pl4 p hci mcpp du1 du2 bb0 bb1 bb2 bb4 bb5 bbg epa msp hgr dhr shr a64 wig

nullstring :=
space := $(nullstring) # need exactly one space after $(nullstring)

all: recoil2png $(if $(CAN_INSTALL_MAGICK),imagemagick/recoil.so) recoil-mime.xml

recoil2png: recoil2png.c pngsave.c pngsave.h recoil.c recoil.h
	$(CC) $(CFLAGS) recoil2png.c pngsave.c recoil.c -lpng -lz -o $@

ifdef CAN_INSTALL_MAGICK
imagemagick/recoil.so: imagemagick/recoilmagick.c recoil.c recoil.h
ifdef MAGICK_INCLUDE_PATH
	$(CC) $(CFLAGS) $(MAGICK_CFLAGS) -I"$(MAGICK_INCLUDE_PATH)" imagemagick/recoilmagick.c recoil.c \
		-shared $(MAGICK_LDFLAGS) -ldl $(MAGICK_LIBS) -o $@;
else
	@echo "\nDetected ImageMagick version $(MAGICK_VERSION) on your system."; \
	echo "To build RECOIL coder for ImageMagick,\nspecify path to ImageMagick sources, e.g.:"; \
	echo "$ make MAGICK_INCLUDE_PATH=/path/to/im/source\n";
endif
endif

# http://www.cmcrossroads.com/article/rules-multiple-outputs-gnu-make
%.c %.h: %.ci atari8.fnt altirrapal.pal c16.pal zx81.fnt
	$(CITO) -o $*.c $<

README.html: README INSTALL
	asciidoc -o - -a recoilsrc README | sed -e "s/527bbd;/800080;/" >$@

benchmark: benchmark.c
	$(CC) $(CFLAGS) benchmark.c recoil.c -o $@

clean:
	rm -f recoil2png imagemagick/recoil.so imagemagick/coder.xml.new recoil-mime.xml benchmark

install: install-thumbnailer $(if $(CAN_INSTALL_MAGICK),install-magick)

uninstall: uninstall-thumbnailer $(if $(CAN_INSTALL_MAGICK),uninstall-magick)

install-recoil2png: recoil2png
	mkdir -p $(PREFIX)/bin
	$(INSTALL_PROGRAM) recoil2png $(PREFIX)/bin/recoil2png

uninstall-recoil2png:
	rm -f $(PREFIX)/bin/recoil2png

ifdef CAN_INSTALL_MAGICK
install-magick: imagemagick/recoil.so
ifdef MAGICK_INCLUDE_PATH
	perl imagemagick/updatecoder.pl $(FORMATS) <$(MAGICK_CONFIG_PATH)/coder.xml >imagemagick/coder.xml.new; \
	mkdir -p "$(MAGICK_CODER_PATH)"; \
	$(INSTALL) imagemagick/recoil.so "$(MAGICK_CODER_PATH)/recoil.so"; \
	echo "dlname='recoil.so'" >"$(MAGICK_CODER_PATH)/recoil.la"; \
	mv imagemagick/coder.xml.new "$(MAGICK_CONFIG_PATH)"/coder.xml;
endif

uninstall-magick:
	perl imagemagick/updatecoder.pl <$(MAGICK_CONFIG_PATH)/coder.xml >imagemagick/coder.xml.new; \
	rm -f "$(MAGICK_CODER_PATH)/recoil.la" "$(MAGICK_CODER_PATH)/recoil.so"; \
	mv imagemagick/coder.xml.new "$(MAGICK_CONFIG_PATH)"/coder.xml;
endif

recoil-mime.xml: recoil-mime.xsl formats.xml
	xsltproc -o $@ recoil-mime.xsl formats.xml

install-mime: recoil-mime.xml
	mkdir -p $(PREFIX)/share/mime/packages
	$(INSTALL_DATA) recoil-mime.xml $(PREFIX)/share/mime/packages/recoil-mime.xml
ifndef BUILDING_PACKAGE
	update-mime-database $(PREFIX)/share/mime
endif

uninstall-mime:
	rm -f $(PREFIX)/share/mime/packages/recoil-mime.xml
	update-mime-database $(PREFIX)/share/mime

install-thumbnailer: install-mime install-recoil2png
	mkdir -p $(PREFIX)/share/thumbnailers
	(echo '[Thumbnailer Entry]' && echo 'Exec=recoil2png -o %o %i' && echo 'MimeType=$(subst $(space),;,$(FORMATS_LC:%=image/x-%))') >$(PREFIX)/share/thumbnailers/recoil.thumbnailer

uninstall-thumbnailer:
	rm -f $(PREFIX)/share/thumbnailers/recoil.thumbnailer

install-gnome2-thumbnailer: install-mime install-recoil2png
	for ext in $(FORMATS_LC); do \
		gconftool-2 --config-source xml:readwrite:/etc/gconf/gconf.xml.defaults -s /desktop/gnome/thumbnailers/image@x-$$ext/command -t string 'recoil2png -o %o %i'; \
		gconftool-2 --config-source xml:readwrite:/etc/gconf/gconf.xml.defaults -s /desktop/gnome/thumbnailers/image@x-$$ext/enable -t boolean true; \
	done

uninstall-gnome2-thumbnailer: uninstall-mime uninstall-recoil2png
	for ext in $(FORMATS_LC); do \
		gconftool-2 -u /desktop/gnome/thumbnailers/image@x-$$ext/command /desktop/gnome/thumbnailers/image@x-$$ext/enable; \
	done

deb:
	debuild -b -us -uc

missing-examples:
	@echo Missing examples for $(foreach EXT,$(FORMATS),$(if $(wildcard ../examples/*.$(EXT)),,$(EXT)))

.PHONY: all clean install uninstall install-recoil2png uninstall-recoil2png $(if $(CAN_INSTALL_MAGICK),install-magick uninstall-magick) install-mime uninstall-mime install-thumbnailer uninstall-thumbnailer install-gnome2-thumbnailer uninstall-gnome2-thumbnailer deb missing-examples

.DELETE_ON_ERROR:
