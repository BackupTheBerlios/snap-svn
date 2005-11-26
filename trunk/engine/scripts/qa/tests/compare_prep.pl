#!/usr/bin/perl
use strict;

my $SEQ = "data/test.seq";
my $WGT = "data/test.wgt";
my $OUTPUT_DIR = "output";
my $NEWSEED = "bin/seed";
my $EXTRA_PARAMS = "--Sseed-n 200 --Sseed-r 0";
my $l;
my $d;
my $exitcode;
my $count;
my $rev;

my $current_time = time;
my $RAND = "--Sproj-i $current_time";


foreach $l (8 .. 12) {
    foreach $d (0 .. 2) {
		foreach $rev ("On", "Off") {
			foreach $count ("Gene", "Total") {
   				my $setting = "L${l}D${d}Rev${rev}$count";
   				mkdir "$OUTPUT_DIR/$setting";
  				
				my $tree_file = "$OUTPUT_DIR/$setting/tree";
				my $leaf_file = "$OUTPUT_DIR/$setting/leaf";
				
				my $run_params = "--Sseed-l $l --Sproj-d $d --Scount-reverse=$rev --Scount $count";

				# run once for each preprocessor
				run_job ($tree_file, "--Sprep tree $run_params");
				run_job ($leaf_file, "--Sprep leaf $run_params");

				# check that the shortened seeds file match
				check_diff ($tree_file, $leaf_file, ".seeds.short");
				
				# check all the psmm and motif files
				my $index = 0;
				foreach $index (1 .. `cat $tree_file.seeds | wc -l`) {
					check_diff ($tree_file, $leaf_file, ".$index.motifs");
					check_diff ($tree_file, $leaf_file, ".$index.neg.motifs");
					check_diff ($tree_file, $leaf_file, ".$index.pssm");
				}
			}
		}
	}
}

sub run_job {
    my ($filename, $specific_params) = @_;
    
    $exitcode = system ("$NEWSEED $RAND $EXTRA_PARAMS $specific_params $SEQ $WGT $filename > $filename.log");
    
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
    $exitcode = system ("diff $first$postfix $second$postfix > $OUTPUT_DIR/last.diff");
    if ($exitcode != 0) {
		print "Output differs, see $first$postfix and $second$postfix\n\n";
		exit;
    }
    unlink "$OUTPUT_DIR/last.diff";
}

    

