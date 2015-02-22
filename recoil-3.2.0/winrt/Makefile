WIN8_SDK = "C:/Program Files (x86)/Windows Kits/8.0"
MAKEAPPX = $(WIN8_SDK)/bin/x86/makeappx.exe
NET45_RA = "C:/Program Files (x86)/Reference Assemblies/Microsoft/Framework/.NETCore/v4.5"

RECOIL.appx: obj/MetroRECOIL.exe obj/AppxManifest.xml obj/Logo.png obj/SmallLogo.png obj/SplashScreen.png obj/FileLogo.png
	$(MAKEAPPX) pack -d obj -o -p $@

obj/MetroRECOIL.exe: MetroRECOIL.cs FilePicker.cs RECOIL.cs
	mkdir -p $(@D) && "C:/Windows/Microsoft.NET/Framework/v4.0.30319/csc.exe" -nologo -o+ -out:$@ -t:appcontainerexe $^ \
		-nostdlib -noconfig -r:$(WIN8_SDK)/References/CommonConfiguration/Neutral/Windows.winmd \
		-r:$(NET45_RA)/mscorlib.dll -r:$(NET45_RA)/System.Diagnostics.Debug.dll -r:$(NET45_RA)/System.Runtime.dll \
		-r:$(NET45_RA)/System.Runtime.WindowsRuntime.dll -r:$(NET45_RA)/System.Threading.Tasks.dll

FilePicker.cs: FilePicker.cs.xsl ../formats.xml
	xsltproc -o $@ $^

RECOIL.cs: ../recoil.ci ../atari8.fnt ../altirrapal.pal ../c16.pal ../zx81.fnt
	cito -o $@ -I .. -n Recoil $<

obj/AppxManifest.xml: AppxManifest.xsl ../formats.xml
	mkdir -p $(@D) && xsltproc -o $@ $^

obj/Logo.png: logo.png
	mkdir -p $(@D) && convert -background none $< -sample 64x64 -extent 150x150-43-30 -quality 95 -strip $@

obj/SmallLogo.png: logo.png
	mkdir -p $(@D) && convert -background none $< -gravity Center -sample 28x28 -extent 30x30 -quality 95 -strip $@

obj/SplashScreen.png: logo.png
	mkdir -p $(@D) && convert -background none $< -gravity Center -sample 280x280 -extent 620x300 -quality 95 -strip $@

obj/FileLogo.png: logo.png
	mkdir -p $(@D) && convert -background "#800080" $< -gravity Center -sample 36x36 -extent 48x48 -quality 95 -strip $@

clean:
	rm -r obj FilePicker.cs RECOIL.cs

.PHONY: clean

.DELETE_ON_ERROR:
