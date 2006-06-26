#!/usr/bin/perl -w 
use strict;
use warnings;

#
# The purpose of this script is to find an IUPAC motif in a sequence file
# and compute a hyper-geometric score for it. it is largely based on ROCMotif script
# written by Tommy Kaplan.
#
# Revision 1: Aviad Roznehek 17/04/05

use Getopt::Long;
use Math::SpecFun::Gamma qw(gammaln);
use SnapUtil;
$| = 1;

# ROCmotif.pl TTACCCGG ~tommy/motif/YoungClean/Data/Yeast.seq ~tommy/motif/YoungClean/Data/REB1_YPD.wgt

#--------------------------------------------------------------------------------

# Parse arguments
my %LChooseCache;
my $HUGE_VAL = 1e100;
my $EPS = log( 1/$HUGE_VAL );

my $debug = 0;
my $nonrev = 0;
my $threshold = 0.5;
my $printall = 0;
my ($ndots, $minPVal) = (250, 1e-8);
my $stub;
GetOptions(
	"threshold:s" => \$threshold,
	"nonreverse" => \$nonrev,
	"long" => \$printall,
	"debug" => \$debug,
	"scorefile:s" => \$stub
	);
	
# LONG = STDOUT;
if (defined ($stub)) {
	# open (LONG, ">$stub.motiffind"); if ($printall)
	open (SCORE, ">$stub");
}
else {
	open (SCORE, ">&STDERR");
}

my $mot = shift;
my $seqfile = shift;
my $wgtfile = shift;
die "Usage: $0 <motif> [-scorefile <filename>] [-nonreverse] [-threshold <t>] [-long] [-debug] <seqfile> <wgtfile>\n"
    unless (defined $mot and defined $seqfile and defined $wgtfile);


# process the motif
my $motif = $mot;
$motif =~ tr/acgtn/ACGTN/;

# uncomment next line to allow (sequence) N where the motif has N
#$motif =~ tr/nN/./;

# motif N matches only ACGT
$motif =~ s/N/[ACGT]/gi;

# Take care of IUPAC
$motif =~ s/S/[CG]/gi;
$motif =~ s/W/[AT]/gi;
$motif =~ s/R/[AG]/gi;
$motif =~ s/Y/[CT]/gi;
$motif =~ s/K/[GT]/gi;
$motif =~ s/M/[AC]/gi;
$motif =~ s/B/[CGT]/gi;
$motif =~ s/D/[AGT]/gi;
$motif =~ s/H/[ACT]/gi;
$motif =~ s/V/[ACG]/gi;

my $revmot = revcom($motif) unless ($nonrev);
if ($nonrev==0) {
    print "motif is $motif\|$revmot\n" if ($debug);
} else {
    print "motif is $motif\n" if ($debug);
}

my ($seqTP, $seqFP, $seqTN) = (0, 0, 0);
my (%d, %wgt);

$d{TP} = $d{TN} = $d{FP} = $d{FN} = 0;
open (W, "$wgtfile") or die "$wgtfile can't be opened\n";
while (<W>) {
    chomp;
    my ($name, $reg) = split(/\t/, $_);
	 next unless (defined ($reg));

    # remove trailiing whitspace
    $name = SnapUtil::trim ($name);
    $wgt{$name}=$reg;
}
close (W);

open (D, "$seqfile") or die "$seqfile can't be opened\n";
my $i = 0;
while (<D>) {
    chomp;
    my $name = $_;
    my $seq = <D>;
    chomp $seq;
    # my ($name, $seq) = split(/\t/, $_);
    next unless (defined $name and defined $seq);
 
    # remove trailiing whitspace
    $name = SnapUtil::trim ($name);    

    my $reg = $wgt{$name};
    next unless (defined ($reg));

    my $match = 0;
#     my @matches = ($seq =~ m/$motif/xgi);

    my @matches;
    my $ind = -1;
    while (1) {
		my $tmpseq = substr($seq, $ind+1);
		$tmpseq =~ m/($motif)/i;
		my $m = $1;
		last unless (defined $m);
		$ind = index($seq, $m, $ind+1);
		last if ($ind == -1);
		print substr ($name,1) . "\t$ind\t+\t$m\t";
		printf "%0.6g", $reg;
		print "\t" . length ($seq) . "\n" if ($printall);
		$match = 1;
    }
    
    if (! $nonrev) {
	while (1) {
	    my $tmpseq = substr($seq, $ind+1);
	    $tmpseq =~ m/($revmot)/i;
	    my $m = $1;
	    last unless (defined $m);
	    $ind = index($seq, $m, $ind+1);
	    last if ($ind == -1);
	    $m = revcom($m);
	    print substr ($name,1). "\t$ind\t-\t$m\t";
	    printf "%0.6g", $reg;
	    print "\t" . length ($seq) . "\n" if ($printall);
	    $match = 1;
	}
    }

    if ($reg > $threshold) {
	$match ? $d{TP}++ : $d{FN}++;
    } else {
	$match ? $d{FP}++ : $d{TN}++;
    }
    $i++;
#     print ".";
#     print " $i\n" if ($i % 100 == 0);
}
# print "\n";

my $X = $d{TP};
my $K = $d{TP} + $d{FP};
my $N = $d{TP} + $d{FN};
my $M = $d{TP} + $d{FN} + $d{FP} + $d{TN};
my $hygepval = exp(ComputeHyperPValue($X, $K, $N, $M));
$seqfile =~ s#.*/##;
$wgtfile =~ s#.*/##;
printf SCORE "%0.5g\n", (- SnapUtil::log10 ($hygepval)); 
printf SCORE "X=%d, K=%d, N=%d, M=%d\n", $X, $K, $N, $M;
#printf STDERR "%-15s %-15s %.7f %.7f TP:%4d FN:%4d FP:%5d TN:%5d  HyGE: %10.5g\n", 
#    $seqfile, $wgtfile,
#    $d{FP}/($d{TN}+$d{FP}),
#    $d{TP}/($d{TP}+$d{FN}),
#    $d{TP}, $d{FN}, $d{FP}, $d{TN}, $hygepval;
close (D);

sub revcom {
    my $a = shift;
    ($a = join("", reverse(split(//, $a)))) =~ tr/acgtACGT[]/tgcaTGCA][/;
    return $a;
}

sub lgamma {
    my $a = shift;
    return gammaln($a);
}

sub lchoose {
    my ($x, $y) = @_;
    die ("**lchoose $x $y") if( $x < 0 || $y < 0 || $x > $y );
    unless (exists $LChooseCache{"$x:$y"}) {
	$LChooseCache{"$x:$y"} = lgamma($y+1) - lgamma($x+1) - lgamma($y-$x+1);
    }
    return $LChooseCache{"$x:$y"};
}

sub AddLog {
    my ($x, $y) = @_;
    return $y if ($x == -$HUGE_VAL);
    return $x if ($y == -$HUGE_VAL);
    if ($x >= $y ) {
	$y -= $x;
    } else {
	my $t = $x;
	$x = $y;
	$y = $t - $x;
    }
    $y = $EPS if ($y < $EPS);
    return ($x + log(1+exp($y)));
}

sub ComputeHyperPValue {
    my ($k, $n, $K, $N) = @_;
    return 0 if ($N == 0);
    my $p = $K*1.0/$N;
    my $d = 1;

    my $PVal = -$HUGE_VAL;
    for( ; $k >= 0 && $k <= $n && $k <= $K && ($n-$k) <= ($N-$K); $k += $d) {
	my $x = lchoose($k,$K) + lchoose($n-$k, $N-$K) - lchoose($n,$N);
	$PVal = AddLog($PVal, $x);
    }
    $PVal = 0 if ($PVal > 0);
    return $PVal;
}

