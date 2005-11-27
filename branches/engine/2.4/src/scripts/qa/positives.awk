#!/usr/bin/gawk -f
# ARGV [1] == wgt file
# ARGV [2] == seq file
BEGIN {
	print "Wgt file = " ARGV[1];  
	print "Seq file = " ARGV[2];
	outfile = sprintf ("%s.pos", ARGV[2]);
	print "creating " outfile;
	
	system ("rm -f " sprintf ("%s.pos", ARGV[2]) );
}

{
	if (ARGIND == 1) {
		# we are in the wgt file
		if (NF > 0) {
			if ($2 > 0.5) {		
				pos_set [$1] = 1;
			}
		}
	}
	else {
		# we are in the seq file, which should be in 1line format
		if ($1 in pos_set) {
			print $0 >> outfile;
		}
	}
}
