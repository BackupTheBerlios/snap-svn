#!/usr/bin/perl

#
# this script is useful for downsizing a .wgt file, by removing some of the "negative" weights.
# the removed weights are chosen randomly according to a seed.
# the number of negative sequences remaining is denoted by 'n'
# Author: Aviad Rozenhek 13/3/05

use strict;
use warnings;
use Getopt::Long;

my $help;
my $thresh = 0.5;
my $ndesired = 1000;
my $srandseed = 0;
GetOptions(
	"threshold:s" => \$thresh,
	"n:s" => \$ndesired,
        "srand:s" => \$srandseed,
	"h" => \$help
	);

if ($help) {
  print "usage: $0 [-n #negatives] [-t thresh] [-srand seed]\n";
  exit (0);
}

if ($srandseed != 0) {
  srand ($srandseed);
}


my @negatives;
my $nposwgt;

# read weights
my $line;
while ($line = <>) {
  chomp $line;
  my ($name, $weight) = split (/\t/,$line);
  next unless (defined ($weight));
  
  if ($weight >= $thresh) {
    # we output all positive weights
    print "$line\n";
    $nposwgt++;
  }
  else{
    push (@negatives, $line);
  }
}

# randomly select sequences from the negative strand
shuffle (\@negatives);

# now output $ndesired negative wgt
my $i;
my $n = min (scalar(@negatives), $ndesired); 
for ($i=0 ; $i<$n ; $i++) {
  print $negatives[$i] ."\n";
}

sub shuffle{
  my $array = shift;
  my $i;
  for ($i = 0 ; $i < @$array ; $i++) {
    my $j = int rand (@$array);
    next if $i == $j;
    @$array[$i,$j] = @$array[$j,$i];
  }
}

sub min {
    my($min) = shift(@_);
    my $temp;
    foreach $temp (@_) {
        $min = $temp if $temp < $min;
    }
    return($min);
}










