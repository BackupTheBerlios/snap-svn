#!/bin/perl

#
# The purpose of this file is to score a given motif file 
# with all possible methods gene/total counts with discrete/real/hotspots weights
#
# the motif file is in simplified format, such as created by find_motif.pl
# or by motif_simplify.pl
#
# the stats file contains information about the size of the positive/negative sets
# and is computed using the wgt_stats.pl file
#
# Revision: Aviad Rozenhek 18/4/05

use warnings;
use strict;

use Math::SpecFun::HyGe;
use SnapUtil;

my $threshold = 0.5;
my $lengh = 0;

my $motiffile = shift;
my $statfile = shift;
die "usage: motif_score.pl <motif_file> <stats_file>\n" .
	"where stats_file is a file created using wgt_stats.pl"
	unless (defined ($statfile));

open (MOTIF, $motiffile) || die "cannot open $motiffile";

# read the first line of the simplified motif file
# this is necessary in order to learn the length of the seed
my $line = <MOTIF>;
close (MOTIF);

# SeqName Offset	Strand	Data	Weight SeqLen
# chr12:862254-862712_YLR371W	171	-	GTTTCA	0.0	730
my ($seqname, $offset, $strand, $data, $weight, $seqlen) = split (/\t+/, $line);
my $length = length ($data);

# now we know the length of the seed
# so we acquire relevant information from the stats file
open (STAT, $statfile) || die "cannot open $statfile";
my $seqfile = <STAT>;
my $wgtfile = <STAT>;
my $header = <STAT>;

$line = <STAT>; 
chomp $line;
my @parsed_line = split (/\t/, $line);

my $gene_discrete_X = 0;
my $gene_discrete_K = 0;
my $gene_discrete_N = $parsed_line [3];	die "error in stats file" unless (defined ($gene_discrete_N));
my $gene_discrete_M = $parsed_line [4];	die "error in stats file" unless (defined ($gene_discrete_M));

$line = <STAT>;
chomp $line;
@parsed_line = split (/\t/, $line);

my $gene_real_X = 0;
my $gene_real_K = 0;
my $gene_real_N = $parsed_line [3];	die "error in stats file" unless (defined ($gene_real_N));
my $gene_real_M = $parsed_line [4];	die "error in stats file" unless (defined ($gene_real_M));

$line = <STAT>;
chomp $line;
@parsed_line = split (/\t/, $line);

my $gene_hotspots_X = 0;
my $gene_hotspots_K = 0;
my $gene_hotspots_N = $parsed_line [3];	die "error in stats file" unless (defined ($gene_hotspots_N));
my $gene_hotspots_M = $parsed_line [4];	die "error in stats file" unless (defined ($gene_hotspots_M));

#
# now we skip a few lines until we get to the line with the relevant length for total counts
foreach my $l ( 1.. (($length - 1) * 3) + 1) {
	$line = <STAT>;
}
chomp $line;
@parsed_line = split (/\t/, $line);

my $total_discrete_X = 0;
my $total_discrete_K = 0;
my $total_discrete_N = $parsed_line [3];	die "error in stats file" unless (defined ($total_discrete_N));
my $total_discrete_M = $parsed_line [4];	die "error in stats file" unless (defined ($total_discrete_M));

$line = <STAT>;
chomp $line;
@parsed_line = split (/\t/, $line);

my $total_real_X = 0;
my $total_real_K = 0;
my $total_real_N = $parsed_line [3];	die "error in stats file" unless (defined ($total_real_N));
my $total_real_M = $parsed_line [4];	die "error in stats file" unless (defined ($total_real_M));

$line = <STAT>;
chomp $line;
@parsed_line = split (/\t/, $line);

my $total_hotspots_X = 0;
my $total_hotspots_K = 0;
my $total_hotspots_N = $parsed_line [3];	die "error in stats file" unless (defined ($total_hotspots_N));
my $total_hotspots_M = $parsed_line [4];	die "error in stats file" unless (defined ($total_hotspots_M));

close (STAT);

# we read the weights file for hotspots data
my %wgt;
SnapUtil::read_hotspotsfile (\%wgt, $wgtfile);

# now we continue reading the motif file
my $last_seqname = "";
my $last_offset = -1;
open (MOTIF, $motiffile) || die "cannot open $motiffile";

my $best_pweight;
while ($line = <MOTIF>) {
	# SeqName Offset	Strand	Data	Weight SeqLen
	# chr12:862254-862712_YLR371W	171	-	GTTTCA	0.0	730
	my ($seqname, $offset, $strand, $data, $weight, $seqlen) = split (/\t+/, $line);
	
	# update hotspots information, using the sequence length
	#SnapUtil::update_hotspots ($wgt {$seqname}, $seqlen);
	
	die "Program error" if (!defined ($wgt{$seqname}));
	
	my $array_ref = $wgt{$seqname}->[2];
	my $pweight = $array_ref->[$offset];
	
	my $overlap = 0;
	if ($seqname ne $last_seqname) {
		# gene counts discrete
		$gene_discrete_X += 1 if ($weight > $threshold);
		$gene_discrete_K++;

		# gene counts real
		$gene_real_X += $weight;
		$gene_real_K++;
		
		# gene counts hotposts
		$best_pweight = $weight;
		$best_pweight *= $pweight if (defined ($pweight));
		$gene_hotspots_X += $best_pweight;
		$gene_hotspots_K++;		
	}
	else {
		# it is the same sequence as before, check for overlaps
		# warning!!! this is the optimal way to remove overlaps
		# BUT ONLY when all the data is of the same length (which it is)
		$overlap = 1 if ($last_offset + $length > $offset);	
		
		#
		# in gene counts we should use the best scoring position of the sequence
		my $current_pweight = $weight;
		$current_pweight *= $pweight if (defined ($pweight));
		if ($current_pweight > $best_pweight) {
			$gene_hotspots_X += $current_pweight - $best_pweight;
			$best_pweight = $current_pweight;
		}
	}

	# total counts
	if (!$overlap) {
		#discrete 
		$total_discrete_X += 1 if ($weight > $threshold);
		$total_discrete_K++;

		#real
		$total_real_X += $weight;
		$total_real_K++;
		
		#hotspots
		my $current_pweight = $weight;
		$current_pweight *= $pweight if (defined ($pweight));
		$total_hotspots_X += $current_pweight;		
		$total_hotspots_K++;
	}
	
	$last_seqname = $seqname;
	$last_offset = $offset;
}

# now we print results
# now print results:
my $H;
print "count"."\t" .  "partial " . "\t" .  "X  "              . "\t" . "K  "              . "\t" . "N   "             . "\t" . "M"                 . "\t" . "HyGe" . "\n";
$H = - SnapUtil::log10 (HyGe::ComputeHyperPValue ($gene_discrete_X, $gene_discrete_K, $gene_discrete_N, $gene_discrete_M));
print "gene " ."\t" . "discrete" . "\t" .  $gene_discrete_X   . "\t" . $gene_discrete_K   . "\t" . $gene_discrete_N   . "\t" . $gene_discrete_M    . "\t" . $H . "\n";

$H = - SnapUtil::log10 (HyGe::ComputeHyperPValue ($gene_real_X, $gene_real_K, $gene_real_N, $gene_real_M));
print "gene " ."\t" . "real    " . "\t" .  int ($gene_real_X) . "\t" . int ($gene_real_K) . "\t" . int ($gene_real_N) . "\t" . int ($gene_real_M)  . "\t" . $H . "\n";

$H = - SnapUtil::log10 (HyGe::ComputeHyperPValue ($gene_hotspots_X, $gene_hotspots_K, $gene_hotspots_N, $gene_hotspots_M));
print "gene " ."\t" . "hotspots    " . "\t" .  int ($gene_hotspots_X) . "\t" . int ($gene_hotspots_K) . "\t" . int ($gene_hotspots_N) . "\t" . int ($gene_hotspots_M)  . "\t" . $H . "\n";

$H = - SnapUtil::log10 (HyGe::ComputeHyperPValue ($total_discrete_X, $total_discrete_K, $total_discrete_N, $total_discrete_M));
print "total" ."\t" . "discrete" . "\t" .  $total_discrete_X  . "\t" . $total_discrete_K  . "\t" . $total_discrete_N  . "\t" . $total_discrete_M   . "\t" . $H. "\n";


$H = - SnapUtil::log10 (HyGe::ComputeHyperPValue ($total_real_X, $total_real_K, $total_real_N, $total_real_M));
print "total" ."\t" . "real    " . "\t" .  int ($total_real_X). "\t" . int ($total_real_K). "\t" . int ($total_real_N). "\t" . int ($total_real_M) . "\t" . $H. "\n";

$H = - SnapUtil::log10 (HyGe::ComputeHyperPValue ($total_hotspots_X, $total_hotspots_K, $total_hotspots_N, $total_hotspots_M));
print "total" ."\t" . "hotspots    " . "\t" .  int ($total_hotspots_X). "\t" . int ($total_hotspots_K). "\t" . int ($total_hotspots_N). "\t" . int ($total_hotspots_M) . "\t" . $H. "\n";
