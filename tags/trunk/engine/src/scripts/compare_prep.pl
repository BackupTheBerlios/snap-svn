#!/usr/bin/perl
use strict;
use diagnostics;
use warnings;

use SnapTest;

my $SEEDBin = shift;
die "Usage: $0 <build1>\n"
    unless (defined $SEEDBin);

my $SEQ = "data/test.seq";
my $WGT = "data/test.wgt";
my $OUTPUT_DIR = "output";
my $EXTRA_PARAMS = "--Sseed-n 75 --Sseed-r 0";
my $SEED1 = "$SEEDBin --Sprep tree";
my $SEED2 = "$SEEDBin --Sprep leaf";
my $SEED1Name = "tree";
my $SEED2Name = "leaf";

# using different preprocessors should give the same results
SnapTest::test ($SEQ, $WGT, $OUTPUT_DIR, $SEED1, $SEED1Name, $SEED2, $SEED2Name, $EXTRA_PARAMS);

# using a small preprocessor should have effect only on speed, not on results
# $SEED1 = "$SEEDBin 
