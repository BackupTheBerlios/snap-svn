#!/usr/bin/perl -w

#
# the purpose of this module is to compute hyper-geometric p-values.
# the author is unknown, perhaps Tommy Kaplan.

package HyGe;
use strict;
use Getopt::Long;
use Math::SpecFun::Gamma qw(gammaln);

my %LChooseCache;
my $HUGE_VAL = 1e100;
my $EPS = log( 1/$HUGE_VAL );


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
    my $PVal = -$HUGE_VAL;

    for( ; $k >= 0 && $k <= $n && $k <= $K && ($n-$k) <= ($N-$K); $k ++) 
    {
	my $x = lchoose($k,$K) + lchoose($n-$k, $N-$K) - lchoose($n,$N);
	$PVal = AddLog($PVal, $x);
    }
    $PVal = 0 if ($PVal > 0);
    return exp($PVal);
}

#-- 
