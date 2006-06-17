#!/usr/bin/perl -w


# This script was created by Tommy Kaplan, Hebrew University, Jerusalm, Israel, 2003.
# tommy@cs.huji.ac.il


use strict;

my $debug = 0;
if (@ARGV > 0 && $ARGV[0] =~ m/^--?d/) {
    $debug = 1;
    shift @ARGV;
}

my (@da, @db);
while (<>) {
    chomp;
    my ($a, $b, @rest) = split(/\s+/, $_);
    push (@da, $a) if (defined $a and $a =~ m/^[\d\.eE-]+$/);
    push (@db, $b) if (defined $b and $b =~ m/^[\d\.eE-]+$/);
}
my $Na = scalar(@da);
my $Nb = scalar(@db);

my $ca = cumu(@da);
my $cb = cumu(@db);

my @va = sort {$a <=> $b} keys %$ca;
my @vb = sort {$a <=> $b} keys %$cb;

# find max dists.
my ($ia, $ib) = (0, 0);
my ($pmaxd, $nmaxd) = (0, 0);
my $pmaxdi = [0, 0];
my $nmaxdi = [0, 0];

while (1) {
    last unless (defined $va[$ia] and defined $vb[$ib]);
    my $diff = $$ca{$va[$ia]} - $$cb{$vb[$ib]};

    # positive
    if ($diff > $pmaxd) {
	$pmaxd = $diff;
	$pmaxdi = [$va[$ia], $vb[$ib]];
    }

    # negative
    if ($diff < $nmaxd) {
	$nmaxd = $diff;
	$nmaxdi = [$va[$ia], $vb[$ib]];
    }

    # possible bug ...
    if ($va[$ia] <= $vb[$ib]) {
	for (; defined ($va[$ia]) and $va[$ia] <= $vb[$ib]; $ia++) {};
    } else {
	for (; defined ($vb[$ib]) and $vb[$ib] <= $va[$ia]; $ib++) {};
    }
}
if ($debug) {
    printf("Max positive Dist = %7.5f (at [%6.3f %6.3f])\n", $pmaxd, @$pmaxdi);
    printf("Max negative Dist = %7.5f (at [%6.3f %6.3f])\n", 0-$nmaxd, @$nmaxdi);
}

my $pc = sqrt($Na*$Nb/($Na+$Nb)) * $pmaxd;
my $nc = sqrt($Na*$Nb/($Na+$Nb)) * $nmaxd;
print "t Scores: [$pc $nc]\n" if ($debug);

my $ppval = score2pval($pmaxd, $Na, $Nb);
$ppval = 1 if ($ppval > 1);
my $npval = score2pval($nmaxd, $Na, $Nb);
$npval = 1 if ($npval > 1);

print "p-Values: (X1 > X2) $ppval   (X2 > X1) $npval\n" if ($debug);
my $pval = ($ppval < $npval) ? $ppval * 2 : $npval * 2;
printf("Two-tailed: %-5g    \tOne-tailed p-values: %-5g %-5g\n", $pval, $ppval, $npval);

sub cumu {
    my %c;
    return \%c unless (@_);

    my @dat = sort {$a <=> $b} @_;
    my $N = scalar (@dat);
    my $step = 1/$N;
    my $integral = 0;
    foreach my $val (@dat) {
	$c{$val} = $integral;
	$integral += $step;
    }
    return \%c;
}

# sub score2pval {
#     my ($maxd, $Na, $Nb) = @_ ;
#     my $t = sqrt($Na*$Nb/($Na+$Nb)) * $maxd;
#     my $pval = 0;
#     for (my $i = 1; $i < 10000; $i++) {
# 	$pval -= (-1 ** ($i-1)) * exp(-2 * ($i**2) * ($t**2));
#     }
#     $pval = 1 if ($pval > 1);
#     $pval = 0 if ($pval < 0);
#     return $pval;
# }

sub score2pval { # matlab version - See KSTEST2
    my ($maxd, $Na, $Nb) = @_ ;
    my $n = ($Na * $Nb) / ($Na + $Nb);
    my $lambda =  (sqrt($n) + 0.12 + 0.11/sqrt($n)) * $maxd;
#     $lambda = 0 if ($lambda < 0);
    my $pval = 0;
    for (my $i = 1; $i <= 101; $i++) {
	$pval  -= (-1 ** ($i-1)) * exp(-2 * ($lambda**2) * ($i**2));
    }
    $pval = 1 if ($pval > 1);
    $pval = 0 if ($pval < 0);
    return $pval;
}	
