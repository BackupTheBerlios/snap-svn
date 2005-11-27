#!/usr/bin/perl 
use strict;

# -w -IF:\perl\lib\bioskills

my $oldseeds_file = shift;
die "Usage: $0 <old-seeds-file>\n"
    unless (defined $oldseeds_file);

open (W, "$oldseeds_file") or die "$oldseeds_file can't be opened\n";
while (<W>) {
    chomp;
    my ($score, $name) = split(/\t/, $_);

# convert score to log 10
    $score = log ($score) / log (1e1);
    print $score;
    print "\t";
    print $name;
    print "\n";
}
close (W);