#!/bin/sh

# the purpose of this file is to provide a common way
# for the sorting of a simplified motif file such as created by the motiffinder.pl 
# and the motif_simplify.pl script
# Revision: Aviad Rozenhek 17/4/05

# we sort the file according to the sequence name and offsets
#sort -t '	' -k 1,1 -k 2n,2n
sort -t '	'