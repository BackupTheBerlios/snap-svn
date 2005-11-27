#! /bin/sh
#
#basic_regress	<seed-l>	<seed-d>	<seed-n>	<seq file> 	<wgt file>	<stb file>
#	$0	$1		$2		$3		$4		$5		$6
if [ $# -lt 6 ] ; then
	echo Not enough arguments
	echo "Usage: $0 <seed-l> <seed-d> <seed-n> <seq file> <wgt file> <stb file>"
	exit 1
fi

NEWSEED=bin/seed
OLDSEED=bin/oldseed
OLDSTUB=$6.old
NEWSTUB=$6.new
OLDLOG=$OLDSTUB.log
NEWLOG=$NEWSTUB.log


# run old-seedsearcher with just one projection
$OLDSEED -l $1 -d $2 -n $3 -m 1 $4 $5 $OLDSTUB

# extract the projection: get the first seed and tranlate acgt to *
gawk '/##AvgMotifNum/ { seeds_start = 1; getline; } ( seeds_start == 1 ) { print $1 "\t" $2; }' $OLDLOG | tr 'N' '?' > $OLDSTUB.seeds
projection=` gawk 'BEGIN { getline; print $2; exit (0);} ' $OLDSTUB.seeds | tr 'aAcCgGtT' '********' `

# run new-seedsearcher without removing redundancies, using the same projection the old-seed gave
$NEWSEED --Sseed-l $1 --Sproj-d $2 --Sseed-n $3 --Sproj-one "$projection" --Sscore-bonf=off --Sseed-r 0 --Sseed-rr=off --Sproj-n 1  $4 $5 $NEWSTUB > $NEWLOG

# now we have to compare the results
# the results in old seed searcher are sorted first by score then by the seed
# so we need to sort the seeds in the new seed searcher. the scores should be in descening order (best first) 
cat $NEWSTUB.seeds | sort -t '	' -k 1,1nr -k 2,2d  > $NEWSTUB.seeds.sorted

#
# now I want to to convert the scores of the old seed to log10 (same as new-seed scores)
detail/basic_regress.pl $OLDSTUB.seeds > $OLDSTUB.seeds.cool

#
# sababa!!! now we we have to:
# 1) discard the seeds with the worst score from both files (because these seeds they may disagree on)
# 2) go over the seeds in order, compare their name and score, and compare their kmer files.
#
# 3) compare the ##AvgMotifNum of oldseed to the "70541 seeds found" in newseed to make sure they
#	are the same (important for bonf correction)
#
# enough said for basic regression tests!
	








