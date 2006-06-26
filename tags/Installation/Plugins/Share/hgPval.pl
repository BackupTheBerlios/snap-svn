#!/usr/bin/perl -w
use strict;
use Getopt::Long;
use Math::SpecFun::Gamma qw(gammaln);
$| = 1;

# hpPval.pl -X -K -M -N 
#--------------------------------------------------------------------------------

# Parse arguments
my %LChooseCache;
my $HUGE_VAL = 1e100;
my $EPS = log( 1/$HUGE_VAL );

##my $X = -1;
##my $K = -1;
##my $N = -1;
##my $M = -1;
###my ($ndots, $minPVal) = (250, 1e-8);
##GetOptions(
##	"X" => \$X,
##	"K" => \$K,
##	"N" => \$N,
##	"M" => \$M,
##	);
##
##die "Usage: $0 -X -K -M -N \n"
##    unless ($X >= 0  and $K >= 0 and $N >= 0 and $M > 0 );
##

my $X = shift;
my $K = shift;
my $N = shift;
my $M = shift;
die "Usage: $0 X K N M\n"
    unless (defined $X and defined $K and defined $N and defined $M);

my $hygepval = exp(ComputeHyperPValue($X, $K, $N, $M));

printf STDOUT "X: %4d K: %4d N: %5d M: %5d  HyGE: %10.5g\n", 
    $X, $K, $N, $M, $hygepval;

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

