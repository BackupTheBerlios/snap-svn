#! /bin/tcsh

##
## basic_regress	<seed-l>	<seed-d>	<seed-n>	<seq file> 	<wgt file>	<stb file>
##	$0	$1		$2		$3		$4		$5		$6

if ($# < 6 ) then
	echo "Not enough arguments"
	echo "Usage: $0 <seed-l> <seed-d> <seed-n> <seq file> <wgt file> <stb file>"
	exit(1)
endif

set NEWSEED = bin/seed
set OLDSEED = bin/oldseed
set OLDSTUB = $6.old
set NEWSTUB = $6.new
set OLDLOG = $OLDSTUB.log
set NEWLOG = $NEWSTUB.log


# run old-seedsearcher with just one projection
echo "$OLDSEED :"
#$OLDSEED -l $1 -d $2 -n $3 -m 1 $4 $5 $OLDSTUB >&! $OLDSTUB.log.stderr

# extract the projection: get the first seed and tranlate acgt to *
cat $OLDLOG | gawk '(index($0,"##AvgMotifNum") > 0) { seeds_start = 1; getline; } ( seeds_start == 1 ) { print $1 "\t" $2; }' | tr 'N' '?' >! $OLDSTUB.seeds
cat  $OLDSTUB.seeds | gawk 'BEGIN { getline; print $2; exit (0); } ' | tr 'aAcCgGtT' '********' >! $OLDSTUB.projection
set projection = `cat $OLDSTUB.projection`


# run new-seedsearcher without removing redundancies, using the same projection the old-seed gave
# and also dont restrict seeds based on bad scores, or if the seed appear in too little of the positive group
echo "$NEWSEED :"
$NEWSEED --Sseed-l $1 --Sproj-d $2 --Sseed-n $3 --Sproj-base "$projection" --Sscore-bonf=off --Sscore-min -10 --Sscore-min-seq-p 0 --Sseed-r 0 --Sseed-rr=off --Sproj-n 1  $4 $5 $NEWSTUB >! $NEWLOG


# now we have to compare the results
# the results in old seed searcher are sorted first by score then by the seed
# so we need to sort the seeds in the new seed searcher. the scores should be in descening order (best first) 
#cat $NEWSTUB.seeds | sort -t '	' -k 1,1nr -k 2,2d  >! $NEWSTUB.seeds.sorted

# keep just the relevant fields from the new seedsearcher
cat $NEWSTUB.seeds | gawk '{print $1"\t"$2;}' > $NEWSTUB.seeds.short

#
# unfortunately, good old oldseedsearcher's results cannot be trusted
# since it allows to find kmers with (sequence) N.
# so we run motiffind.pl on oldseed's results


#
# now I want to to convert the scores of the old seed to log10 (same as new-seed scores)
detail/basic_regress.pl $OLDSTUB.seeds >! $OLDSTUB.seeds.cool

diff $OLDSTUB.seeds.cool $NEWSTUB.seeds.short

#
# sababa!!! now we we have to:
# 1) discard the seeds with the worst score from both files (because these seeds they may disagree on)
# 2) go over the seeds in order, compare their name and score, and compare their kmer files.
#
# 3) compare the ##AvgMotifNum of oldseed to the "70541 seeds found" in newseed to make sure they
#	are the same (important for bonf correction)
#
# enough said for basic regression tests!
