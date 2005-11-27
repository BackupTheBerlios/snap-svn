#!/usr/bin/csh
# $1 == motif
# $2 == wgt file
# $3 == seq file

echo searching for $1 in $3.pos
echo

gawk -f positives.awk  $2 $3
gawk -f negatives.awk $2 $3

echo positives: `grep $1 "$3.pos" | wc -l` of `cat $3.pos | wc -l`
echo negatives: `grep $1 $3.neg| wc -l` of `cat $3.neg | wc -l`
