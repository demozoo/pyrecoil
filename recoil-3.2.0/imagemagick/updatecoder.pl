#!/usr/bin/perl

use XML::DOM;

local $/;
my $doc = (new XML::DOM::Parser)->parse(<STDIN>);
my $codermap = $doc->getDocumentElement();
for my $coder ($codermap->getChildNodes()) {
	if ($coder->getNodeType == ELEMENT_NODE && $coder->getTagName eq "coder" && $coder->getAttribute("name") eq "RECOIL") {
		$codermap->removeChild($coder);
	}
}
for (@ARGV) {
	my $coder = $doc->createElement("coder");
	$coder->setAttribute("magick", $_);
	$coder->setAttribute("name", "RECOIL");
	$codermap->appendChild($coder);
}
$doc->printToFileHandle(\*STDOUT);

