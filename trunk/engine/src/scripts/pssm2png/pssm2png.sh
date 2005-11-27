#!/bin/csh -f 

makefig.sh $1 > $1:t:r.eps
# convert is downloadable from www.imagemagick.org
convert -rotate 270 $1:t:r.eps $1:t:r.png
#rm -f /tmp/$1:t:r.eps
echo $1:t:r.png

