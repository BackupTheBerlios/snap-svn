#!/usr/bin/perl
use strict;
use diagnostics;
use warnings;

package SnapTest;

return 1;

#
# compares two versions of seedsearcher (or same version with different parameters)
sub test {
   my ($SEQ, $WGT, $OUTPUT_DIR, $SEED1, $SEED1Name, $SEED2, $SEED2Name, $EXTRA_PARAMS) = @_;

   my $current_time = time;
   my $RAND = "--Sproj-i $current_time";
  
   my $l;
   my $d;
   my $rev;
   my $count;
   my $partial;
   my $score;
   
   foreach $l (6, 8, 12) {
      foreach $d (0, 2, 4) {
         foreach $rev ("On", "Off") {
            foreach $count ("Gene", "Total") {
               foreach $partial ("Off", "On", "Hotspots") {
                  foreach $score ("Hypegeo", "exp:1.5:1.8") {
                        my $setting = substr($score,0, 3)."L${l}D${d}Rev${rev}${count}Partial$partial";
                        mkdir "$OUTPUT_DIR/$setting";

                        my $file1 = "$OUTPUT_DIR/$setting/$SEED1Name";
                        my $file2 = "$OUTPUT_DIR/$setting/$SEED2Name";

                        my $run_params = "$RAND --Sseed-l $l --Sproj-d $d --Scount-reverse=$rev --Scount $count --Sscore-partial=$partial --Sscore-t $score $EXTRA_PARAMS $SEQ $WGT";

                        # run once for each preprocessor
                        my $ok = 1;
                        my $ok1 = 1;
                        my $ok2 = 1;
                        print "\n", $setting, ":\n";
                        $ok1 = run_job ($file1, "$SEED1 $run_params");
                        $ok2 = run_job ($file2, "$SEED2 $run_params");
                        $ok = $ok1 && $ok2;
                        if ($ok) {
                           $ok = compare_jobs ($file1, $file2, $OUTPUT_DIR);
                        }

                        if (!$ok) {
                           select((select(STDOUT),$|=1)[0]); # flush buffer after every byte
                           print "press ctrl-c now to stop the script";
                           foreach (1 .. 5) { 
                              sleep (1); 
                              print "."; 
                           };
                           print " continuing\n";
                           select((select(STDOUT),$|=0)[0]); # resume standard flushing                           
                        }
                  }
               }
            }
         }
      }
   }
}


#
# runs a seedsearcher job, exits if fails, creates a shortened seeds file
sub run_job {
    my ($filename, $cmdline) = @_;
    
    my $ok = 1;
    my $exitcode = system ("$cmdline $filename > $filename.log");
    
    if ($exitcode != 0) {
      printf "process failed, see $filename.log for details\n\n";
      #exit 1;
      $ok = 0;
    }
    else {
       remove_filename_from_seedfile ("$filename.seeds");
    }
    
    return $ok;
}

sub compare_jobs ($$ $$ $$) {
   my ($file1, $file2, $OUTPUT_DIR) = @_;
   # check that the shortened seeds file match
   check_diff ($file1, $file2, ".seeds.short", $OUTPUT_DIR) || return;

   # check all the psmm and motif files
   my $ok = 1;
   my $index = 0;
   foreach $index (1 .. `cat $file1.seeds | wc -l`) {
      $ok = check_diff ($file1, $file2, ".$index.motifs", $OUTPUT_DIR)        || last;
      $ok = check_diff ($file1, $file2, ".$index.neg.motifs", $OUTPUT_DIR)    || last;
      $ok = check_diff ($file1, $file2, ".$index.pssm", $OUTPUT_DIR)          || last;
   }
   
   return $ok;
}


#
# creates a shortened seeds file without file names
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

#
# performs a diff between two files
sub check_diff {
    my $ok = 1;
    my ($first, $second, $postfix, $OUTPUT_DIR) = @_;
    my $exitcode = system ("diff $first$postfix $second$postfix > $OUTPUT_DIR/last.diff");
    if ($exitcode != 0) {
      print "Output differs, see $first$postfix and $second$postfix\n\n";
      # exit;
      $ok = 0;
    }
    unlink "$OUTPUT_DIR/last.diff";
    return $ok;
}
