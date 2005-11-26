#!/usr/bin/perl -w

#
# this module provides useful utility functions 
# Revision: Aviad Rozenhek 17/4/05

package SnapUtil;
use strict;

sub trimleft {
	my ($arg) = @_;
	my $replaced = $arg;
	$replaced =~ s/^\s*//g;
#	print "$replaced=$arg\n";
	return $replaced;
}

sub trimright {
	my ($arg) = @_;
	my $replaced = $arg;
	$replaced =~ s/\s*$//g;	
#	print "$replaced=$arg\n";
	return $replaced;
}

sub trim {
	my ($arg) = @_;
	my ($replaced) = trimright (trimleft ($arg));
#	print "$replaced=$arg\n";
	return $replaced;
}

sub log10 {
	my ($arg) = @_;
	return log ($arg) / log (10);
}

sub read_wgtfile {
	my ($wgtfilename) = @_;
	
	my %wgt;
	open (W, "$wgtfilename") or die "$wgtfilename can't be opened\n";
	while (<W>) {
		 chomp;
		 my ($name, $reg) = split(/\t/, $_);

		 # remove trailiing whitspace and the prepending >
		 $name = trim (substr ($name, 1));
		 $wgt{$name}=$reg;
	}
	close (W);
	
	return %wgt;
}

sub read_hotspotsfile {
	my ($wgt_ref, $wgtfilename) = @_;
	
	#my %wgt;
	open (W, "$wgtfilename") or die "$wgtfilename can't be opened\n";
	while (<W>) {
		 chomp;
		 my @parsed_line = split(/\t+/, $_);
		 my $name = trim (substr ($parsed_line [0], 1));
		 my $weight = $parsed_line [1];
		 my $length = @parsed_line;
		 
		 my @posweights;
		 foreach my $i (2 .. $length - 1) {
		 	$parsed_line [$i] =~ m/(.*?)=\[(.*?),(.*?)\]/;
		 	my ($pweight, $pstart, $pend) = ($1, $2, $3);
		 	die "bad hotspots file in $name" unless defined ($pend);
		 	
		 	foreach my $p ($pstart .. $pend) {
		 		$posweights [$p] = $pweight;
	 		}
		 }
		 
		 # remove trailiing whitspace
		 $name = trim ($name);
		 
		 # the format is the every entry in the wgt hash is an array ref with
		 # base-weight, weight-sum, positional-weights-ref
		 $$wgt_ref{$name}= [ $weight, 0, \@posweights ];
		 #my $array_ref = $$wgt_ref{$name}->[2];
		 #print @$array_ref . "\t$name miew \n";
		 #@posweights . "\n";
	}
	close (W);
}

# the purpose of this function is to update a hotspots entry
# with the average weight of the sequence, for which it is necessary
# to know the length of the sequence
sub update_hotspots {
	my ($hotspots_ref, $seqlen) = @_;
	my $baseweight = $hotspots_ref->[0];
	my $posweights_ref = $hotspots_ref->[2];
	
	my $sum = 0;
	foreach my $i (0 .. $seqlen - 1) {
		my $pweight = 1;
		$pweight = $posweights_ref->[$i] if (defined ($posweights_ref->[$i]));
		$sum += $pweight * $baseweight;
	}
	
	$hotspots_ref->[1] = $sum / $seqlen;
}

return 1;
#-- 