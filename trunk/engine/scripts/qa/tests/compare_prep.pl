#!/usr/bin/perl
use strict;

my $SEQ = "data/test.seq";
my $WGT = "data/test.wgt";
my $OUTPUT_DIR = "output";
my $NEWSEED = "bin/seed";
my $EXTRA_PARAMS = "--Sseed-n 75 --Sseed-r 0";
my $l;
my $d;
my $exitcode;


my $current_time = time;
my $RAND = "--Sproj-i $current_time";


foreach $l (8 .. 12) {
    foreach $d (0 .. 4) {
    	my $setting = "L${l}D${d}";
	my $tree_file = "output/tree$setting";
	my $leaf_file = "output/leaf$setting";

	# run once for each preprocessor
	run_job ($tree_file, "--Sprep tree", $l, $d);
	run_job ($leaf_file, "--Sprep leaf", $l, $d);

	# check that the shortened seeds file match
	check_diff ("output/tree", "output/leaf", "$setting.seeds.short");
	
	# check all the psmm and motif files
	my $index = 0;
	foreach $index (1 .. `cat $tree_file.seeds | wc -l`) {
		check_diff ("output/tree", "output/leaf", "$setting.$index.motifs");
		check_diff ("output/tree", "output/leaf", "$setting.$index.neg.motifs");
		check_diff ("output/tree", "output/leaf", "$setting.$index.pssm");
	}
    }
}

sub run_job {
    my ($filename, $specific_params, $l, $d) = @_;
    
    $exitcode = system ("$NEWSEED $RAND $EXTRA_PARAMS $specific_params --Sseed-l $l --Sproj-d $d $SEQ $WGT $filename > $filename.log");
    
    if ($exitcode != 0) {
	printf "process failed, see $filename.log for details\n\n";
	exit 1;
    }
    
    remove_filename_from_seedfile ("$filename.seeds");
}


sub remove_filename_from_seedfile {
    my ($filename) = @_;
    open (SEEDFILE, $filename) || die "cant open seeds file $filename";
    open (OUTPUTFILE, ">$filename.short") || die "cant open output file $filename.short";

    my $line;
    my @parsed_line;
    while ($line = <SEEDFILE>) {
	@parsed_line = split (/\t/, $line);
	@parsed_line = splice (@parsed_line, 0, 4);
	$line = join ("", @parsed_line);
	print OUTPUTFILE $line, "\n" || die "cant write to the file";
    }
    close SEEDFILE;
    close OUTPUTFILE;
}

sub check_diff {
    my ($first, $second, $postfix) = @_;
    $exitcode = system ("diff $first$postfix $second$postfix > $postfix.diff");
    if ($exitcode != 0) {
	print "Output differs, see $first.$postfix and $second.$postfix\n\n";
	exit;
    }    
}

    

