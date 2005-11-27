#!/usr/bin/perl
use strict;
use diagnostics;
use warnings;

use SnapTest;


my $SEED1Name = shift;
my $SEED2Name = shift;
die "Usage: $0 <build1> <build2>\n"
    unless (defined $SEED1Name and defined $SEED2Name);

my $SEQ = "data/test.seq";
my $WGT = "data/test.wgt";
my $OUTPUT_DIR = "output";
my $NEWSEED = "bin/seed";
my $EXTRA_PARAMS = "--Sseed-n 75 --Sseed-r 0 --Sscore-min -10 --Sscore-min-seq 0 --Sscore-min-seq-p 0";
my $SEED1 = "bin/$SEED1Name";
my $SEED2 = "bin/$SEED2Name";

my $prep;
foreach $prep ("tree", "leaf") {
   SnapTest::test ($SEQ, $WGT, $OUTPUT_DIR, $SEED1, $SEED1Name, $SEED2, $SEED2Name, "$EXTRA_PARAMS --Sprep $prep");
}