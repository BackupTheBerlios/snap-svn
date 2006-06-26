#!/bin/perl

#
# The purpose of this file is to compute statistics about the size of the
# positive and negatives sets of a given seq file & wgt file
# basically it computes the N, M of the hyper-geometric score
#
# Revision: Aviad Rozenhek 18/4/05 

use warnings;
use strict;

use SnapUtil;

my $threshold = 0.5;

my $seqfile = shift;
my $wgtfile = shift;
die "usage: wgt_stats <seqfile> <wgtfile>\n" unless (defined ($wgtfile));

my $gene_discrete_N = 0;
my $gene_discrete_M = 0;

my $gene_real_N = 0;
my $gene_real_M = 0;

my $gene_hotspots_N = 0;
my $gene_hotspots_M = 0;

my @total_discrete_N;
my @total_discrete_M;

my @total_real_N;
my @total_real_M;

my @total_hotspots_N;
my @total_hotspots_M;

open (SEQ, "$seqfile") || die "cannot open $seqfile";

my %wgt = SnapUtil::read_hotspotsfile ($wgtfile);
while (<SEQ>) {
    chomp;
    my $name = $_;
    my $seq = <SEQ>;
    chomp $seq;
    next unless (defined $name and defined $seq);
    
    # remove trailiing whitspace
    $name = SnapUtil::trim ($name);    
    $seq = SnapUtil::trim ($seq);    
    
    my $reg = $wgt{$name}->[0];
    next unless (defined ($reg));
    
    # phew! we have a seq with a weight...
    
    $gene_discrete_N += 1 if ($reg > $threshold);
    $gene_discrete_M++;
    
    $gene_real_N += $reg;
    $gene_real_M++;
    
    $gene_hotspots_N += $reg;
    $gene_hotspots_M += 1;

	#
	# we will compute the N, M for every conceivable length
    foreach my $l ( 1 .. 20) {
    	$total_discrete_N [$l] += int (length ($seq) / $l) if ($reg > $threshold);
    	$total_discrete_M [$l] += int (length ($seq) / $l);
    	
    	$total_real_N [$l] +=  int (length ($seq) / $l) * ($reg);
    	$total_real_M [$l] +=  int (length ($seq) / $l);
    	
    	$total_hotspots_N [$l] += int (length ($seq) / $l) * $reg;
	   $total_hotspots_M [$l] += int (length ($seq) / $l);    	
    }
}

close (SEQ);

print $seqfile . "\n";
print $wgtfile . "\n";

# now print results:
print "count"."\t" . "partial " . "\t" . "seed-l" ."\t" . "N" . "\t" . "M\n";
print "gene" ."\t" . "discrete" . "\t" . "* " .    "\t" . "$gene_discrete_N" . "\t" . "$gene_discrete_M\n";
print "gene" ."\t" . "real    " . "\t" . "* " .    "\t" . int ($gene_real_N) . "\t" . int ($gene_real_M) . "\n";
print "gene" ."\t" . "hotspots    " . "\t" . "* " .    "\t" . int ($gene_hotspots_N) . "\t" . int ($gene_hotspots_M) . "\n";

foreach my $l ( 1 .. 20) {
	print "total" ."\t" . "discrete" . "\t" . $l . "\t" . int ($total_discrete_N [$l]) . "\t" . int ($total_discrete_M [$l]) ."\n";
	print "total" ."\t" . "real    " . "\t" . $l . "\t" . int ($total_real_N [$l]) . "\t" . int ($total_real_M [$l]) ."\n";
	print "total" ."\t" . "hotspots    " . "\t" . $l . "\t" . int ($total_hotspots_N [$l]) . "\t" . int ($total_hotspots_M [$l]) ."\n";
}



