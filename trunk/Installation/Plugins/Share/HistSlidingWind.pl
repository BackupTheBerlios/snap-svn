#! /usr/bin/perl -w 
use Getopt::Long;
use strict;

# This script takes as input an ordered  list of positions and creates a histogram for them.
# It is based on the theory of parzen Windows for aprametric probability disribution estimation.
# The size of the bins is Vn = 500/sqrt(n) where n is the number of samples
# and P_n(x) = 1/n * \sum_{i=1}^n 1/Vn \Phi(x_n - x) and Phi() is an indiator function which gets 1 if the the distance between the two points is no more then Vn/2 
# This means that for 10 samples you get bin sizes of ~150bp, for 100 samples we get bin sizes of 50bp.
# The first argument is the relevant field index (I), assuming tab seperation.
# Note: assumes the list is already ordered !!
my $file = undef;
my $I = 0;
my $minVal = undef;
my $maxVal = undef;
GetOptions(
	  "In:s" => \$file,
	  "field:i" => \$I,
	  "min:i" => \$minVal,
	  "max:i" => \$maxVal
	  );
my @usage = ( "$0 -In filename [options]\n",
	      "-field = field index to use (tab seperation)default: 0\n",
	      "-min = minimum (x) value for the histogram (might be bigger though)\n",
	      "-max = maximum (x) value for the histogram (might be smaller though)\n",
	      "Note: (1) default x range is [minX,maxX] as observed in the list\n",
	      "      (2) V1 is set as (max-min)\n");

die "No input file speficifed\n" unless (defined $file);
die "Got to have max > min\n" if (defined $minVal && defined($maxVal) && ($minVal >= $maxVal) );
open F, "<$file" or die "cannot open $file $!\n";

my $count = 0;
my $totalCount = 0;
my %sample;
my %sampleCount;
my $firstPosition = undef;
my $lastPosition = undef;
my %P;
while (<F>) {
  next if( m/^#/); # skip lines that start with a comment
  next if( m/^#/); # skip lines that start with a comment
  my @fields = split/\t/,$_;
  next unless (@fields); # skip empty lines
  next unless ($fields[$I]); #skip lines with an ampty attribute
  $totalCount++;
  if ($totalCount == 1) {
    $count++;
    $firstPosition = $fields[$I];
    $sample{$count} = $fields[$I];
    $sampleCount{$count}++;
    $lastPosition = $fields[$I];
  }
  else {  
    $count++ if ( $fields[$I] != $lastPosition );
    $sample{$count} = $fields[$I];
    $sampleCount{$count}++;
    $lastPosition = $fields[$I];
  }
}

die "empty file\n" if ( $totalCount == 0);

# set the limits not be more then min/maxVal, if these are given:
$firstPosition = $minVal if ( (defined $minVal) && ($firstPosition <  $minVal));
$lastPosition = $maxVal if ( (defined $maxVal) && ($lastPosition >  $maxVal));
die ("got to set min max values so that firstPosition < lastPosition") if ($firstPosition >=  $lastPosition);
my $V1 = (defined ($minVal) && defined ($maxVal)) ? $maxVal-$minVal : $lastPosition - $firstPosition;
my  $Vn = ($totalCount > 0 ) ? int ($V1/sqrt($totalCount)) : 0;
my  $maxDist = $Vn*1.0 / 2.0;
my $lastStartIndex = 1;
for ( my $i = $firstPosition;$i<= $lastPosition;$i++) {
  my $currCount = 0;
  my $inRange = 0; # flag to indicate we got into the range of samples around our current point
  for (my $j = $lastStartIndex;$j<= $count;$j++) {
      my $dist = sqrt( ($sample{$j} - $i) * ($sample{$j} - $i));
      if ($dist <= $maxDist) {
	$currCount += $sampleCount{$j};
	if ($inRange == 0) {
	  $inRange = 1;
	  $lastStartIndex = $j;
	}
      }
      # if we got out of range again then break scanning the rest of the points which are even more far..
      else {
	last if ( ($dist > $maxDist) && ($inRange == 1));
      }
    }
    $P{$i} = $currCount*1.0/($Vn*$totalCount);
}
#print the resulting histogram,:
for ( my $i = $firstPosition;$i<= $lastPosition;$i++) {
  print "$i\t$P{$i}\n";#"\t"C[i];
}
