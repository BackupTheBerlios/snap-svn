#!/bin/perl

# the purpose is to convert seedsearcher .motif & .neg.motif output
# into a file which should be identical with motiffind.pl output
# Revision: Aviad Rozenhek 17/4/05

use warnings;
use strict;

use SnapUtil;

my $stub = shift;
die "usage: simplifymotif.pl <motif-base-filename>" 
	if (!defined ($stub));

for my $filename ("$stub.motifs" , "$stub.neg.motifs") {
	die "the $filename does not exist" if (!(-e $filename));
	open (FILE, "$filename") || die "cannot open $filename";
	
	# discard header
	my $header = <FILE>;

	#SeedSearcher fields:
	#Actual-Data (expanded) 
	#Seq-ID
	#Seq-Name
	#Seq-Weight (enclosed in [])
	#TSS-Start-Offset
	#TSS-End-Offset
	#Strand	

	#motiffind.pl fields:
	#Seq-Name
	#TSS-Start-Offset
	#Strand	
	#Actual-Data
	#Seq-Weight

	while (	my $line = <FILE>) {
		my ($expdata, $id, $name, $encweight, $offset, $endoffset, $strand, $seqlen) = split(/\t/, $line);

		$expdata =~ m/ (.*?) / ;	my $data = $1;
		$encweight =~ m/\[(.*)\]/;	my $weight = $1;
		
		# offset is upstream from tss, so we need to convert it to offset from beginning of sequence
		$offset = $endoffset if (SnapUtil::trim ($strand) eq "-"); 
		$offset +=  $seqlen;
				
		print SnapUtil::trim ($name) . "\t";
		print SnapUtil::trim ($offset) . "\t";
		print SnapUtil::trim ($strand) . "\t";
		print SnapUtil::trim ($data) . "\t";
		print SnapUtil::trim ($weight) . "\t";
		print SnapUtil::trim ($seqlen) . "\n";
		
	}
	
	close (FILE);
}
