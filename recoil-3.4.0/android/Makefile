ANDROID_SDK = C:/bin/android-sdk-windows
ANDROID_JAR = $(ANDROID_SDK)/platforms/android-19/android.jar
ANDROID_BUILD_TOOLS = $(ANDROID_SDK)/build-tools/21.1.2

AAPT = $(ANDROID_BUILD_TOOLS)/aapt
DX = java -jar "$(ANDROID_BUILD_TOOLS)/lib/dx.jar" --no-strict
JARSIGNER = jarsigner -sigalg SHA1withRSA -digestalg SHA1
ZIPALIGN = $(ANDROID_BUILD_TOOLS)/zipalign
ADB = $(ANDROID_SDK)/platform-tools/adb
ANDROID = $(ANDROID_SDK)/tools/android.bat
EMULATOR = $(ANDROID_SDK)/tools/emulator

ANDROID_RELEASE = recoil-3.4.0-android.apk

all: $(ANDROID_RELEASE) recoil-1024x500.png

install-dev: $(ANDROID_RELEASE)
	$(ADB) -d install -r $<

install-emu: $(ANDROID_RELEASE)
	$(ADB) -e install -r $<

log-dev:
	$(ADB) -d logcat

$(ANDROID_RELEASE): AndroidRECOIL-unaligned.apk
	$(ZIPALIGN) -f 4 $< $@

AndroidRECOIL-unaligned.apk: AndroidRECOIL-unsigned.apk
	$(JARSIGNER) -storepass walsie -signedjar $@ $< pfusik

AndroidRECOIL-unsigned.apk: AndroidRECOIL-resources.apk classes.dex
	cp $< $@ && 7z a -mx=9 -bd -tzip $@ ./classes.dex

classes.dex: classes/net/sf/recoil/RECOIL.class
	$(DX) --dex --output=$@ classes

classes/net/sf/recoil/RECOIL.class: AndroidSupport.java FavoriteSelector.java FileSelector.java FileUtil.java GalleryAdapter.java JavaRECOIL.java Viewer.java gen/net/sf/recoil/RECOIL.java AndroidRECOIL-resources.apk
	mkdir -p classes && javac -d classes -bootclasspath $(ANDROID_JAR) AndroidSupport.java FavoriteSelector.java FileSelector.java FileUtil.java GalleryAdapter.java JavaRECOIL.java Viewer.java gen/net/sf/recoil/*.java

gen/net/sf/recoil/RECOIL.java: ../recoil.ci ../atari8.fnt ../altirrapal.pal ../c16.pal ../zx81.fnt
	mkdir -p $(@D) && cito -n net.sf.recoil -o $@ -I .. $<

AndroidRECOIL-resources.apk: AndroidManifest.xml res/drawable/ic_launcher.png res/layout/access_denied.xml res/layout/error.xml res/layout/filename_list_item.xml res/layout/gallery.xml res/layout/no_files.xml \
	res/menu/file_selector.xml res/menu/viewer.xml res/values/strings.xml res/values-pl/strings.xml \
	assets/net/sf/recoil/atari8.fnt assets/net/sf/recoil/altirrapal.pal assets/net/sf/recoil/c16.pal assets/net/sf/recoil/zx81.fnt
	mkdir -p gen && $(AAPT) p -f -m -M $< -I $(ANDROID_JAR) -S res -F $@ -J gen assets

res/drawable/ic_launcher.png: ../recoil-512x512.png
	mkdir -p $(@D) && convert $< -resize 72x72 -quality 95 -strip $@

assets/net/sf/recoil/%: ../%
	mkdir -p $(@D) && cp $< $@

AndroidManifest.xml: AndroidManifest.xsl ../formats.xml
	xsltproc -o $@ AndroidManifest.xsl ../formats.xml

recoil-1024x500.png: ../recoil-512x512.png
	convert $< -crop 334x163+89+140 -sample 1024x500 -quality 95 -strip $@

clean:
	$(RM) *.apk classes.dex res/drawable/ic_launcher.png AndroidManifest.xml recoil-1024x500.png
	rm -rf classes gen assets

.PHONY: all install-dev install-emu log-dev clean

.DELETE_ON_ERROR:
