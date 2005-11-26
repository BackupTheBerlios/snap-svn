#!/usr/bin/perl
use strict;
use warnings;

my $oldseeds_file = shift;

die "Usage: $0 [-nonreverse] <stub>\n"
    unless (defined $oldseeds_file);

# -w -IF:\perl\lib\bioskills

while (<>) {
    chomp;
    my ($score, $name) = split(/\t/, $_);

    #run motiffind on the seed found
    system ("(motiffind.pl -long $name > $stub.motifs) >& $stub.log");
    
    

# convert score to -log 10
    $score = log ($score) / log (1e1);
    printf ("%0.6g", -$score);
    print "\t";
    print $name;
    print "\n";
}
close (W);





# -w -IF:\perl\lib\bioskills

my $oldseeds_file = shift;
die "Usage: $0 <old-seeds-file>\n"
    unless (defined $oldseeds_file);

open (W, "$oldseeds_file") or die "$oldseeds_file can't be opened\n";
while (<W>) {
    chomp;
    my ($score, $name) = split(/\t/, $_);

# convert score to -log 10
    $score = log ($score) / log (1e1);
    printf ("%0.6g", -$score);
    print "\t";
    print $name;
    print "\n";
}
close (W);
