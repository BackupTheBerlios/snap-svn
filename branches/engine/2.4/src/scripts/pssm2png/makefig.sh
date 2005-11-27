#!/bin/csh -f

cat logos/header
awk -f logos/makefig.awk $1
cat logos/footer
