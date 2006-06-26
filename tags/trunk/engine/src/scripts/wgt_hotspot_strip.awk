#!/usr/bin/gawk -f
# the purpose of this file is to strip positional-bias (hotspots) data from .cwgt files
# in order to convert them back to .wgt files without positional-bias
#
# File        : $RCSfile: $ 
#               $Workfile: strip_hotspots.awk $
# Version     : $Revision: 1 $ 
#               $Author: Aviad $
#               $Date: 17/4/05 21:45 $ 
{ print $1 "\t" $2 ; }
