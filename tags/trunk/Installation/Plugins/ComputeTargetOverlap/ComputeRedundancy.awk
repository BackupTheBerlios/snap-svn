# This (reconstructed ) file computed the phisical overlap between two .motifs files
# NOTE:
# 1. The computation tolerates up to THRESH ofset between the two seeds positions
# 2. Also, it takes into account the difference in length between the 2 seeds so that:
# this all these are considerd redundant sites for THRESH =1:
#  ---------
# ----
#
# up to this:
#  ---------
#        ----
#
# 3. the ratio of redundant sites is always relative to the seed with the fewer sites!

BEGIN {
  thresh[5] = 1;
  thresh[6] = 2;
  thresh[7] = 2;
  for ( i = 8;i<= 14;i++)
    thresh[i] = 3;
  FS = "\t";
  # find out which seed  has less sites, and make sure it is read first:
  for ( i = 1;i<= 2;i++) {
    getline <ARGV[i];
    while ( getline <ARGV[i]) {	
	if (NF > 0) {
	    nf = split($1,a," ");
	    len[i] = (nf == 3) ? length(a[2]) : a[1];
	}
	count[i]++;
    }
    close(ARGV[i]);
  }
##  print "len[1] " len[1]" len[2] " len[2];
##  print "count[1] "count[1] " count[2] " count[2];
  if (count[2] < count[1]) {
    tmp = ARGV[1];
    ARGV[1]= ARGV[2];
    ARGV[2] = tmp;
  }
}

( (ARGIND == 1) && (FNR > 1) && (NF > 0)) {
#    print $0;
    seq = $2;
    s1Seqs[seq]++;
    s1Sites[seq,s1Seqs[seq]] = $5;
    s1SiteNum++;
    nf = split($1,a," ");  
    s1len = (nf == 3) ? length(a[2]) : a[1];
    print "s1len "s1len;
}

( (ARGIND == 2) && (FNR > 1) && (NF > 0) ) {
#    print $0;
    seq = $2;
    s2Seqs[seq]++;
    s2Sites[seq,s2Seqs[seq]] = $5;
    s2SiteNum++;
    nf = split($1,a," ");  
    s2len = (nf == 3) ? length(a[2]) : a[1];
    print "s2len "s2len;
}

END {
  # take sites number to be the min of the total of each motif:
  #print "s1SiteNum " s1SiteNum " s2SiteNum " s2SiteNum;
  siteNum = s1SiteNum; # which is the minimum of the two
  rdCount = 0;
  minLen = ( s1len < s2len) ? s1len : s2len;
  if ( ! (minLen  in thresh) ) {
    print "ERROR: minLen " minLen " not in thresh array, aborting...";
    exit(2);
  }
  else
    THRESH = thresh[minLen];
  if ( s1len >= s2len) {
    lenDiff = s1len - s2len;
    posOffset = THRESH;
    negOffset = -1*(THRESH + lenDiff);
  }
  else {
    lenDiff = -1*(s1len - s2len);
    posOffset = (THRESH + lenDiff);
    negOffset = -1*THRESH;
  }
  # DEBUG:
#  THRESH = 5;
#  lenDiff = 5;
  # END DEBUG
#  print "siteNum "siteNum " lenDiff " lenDiff;
  for (seq in s1Seqs) {
#    print "seq in s1Seqs " seq;
    if (! ( seq in s2Seqs)) 
      continue;
    for ( i = 1;i <= s1Seqs[seq]; i++) {
      pos1 = s1Sites[seq,i];
      for ( j = 1;j <= s2Seqs[seq]; j++) {
	pos2 = s2Sites[seq,j];
	dist = pos1 - pos2;
#	print "pos1 " pos1 " pos2 "pos2 " dist " dist;
#	exit(2);
	if ( ( (dist >= 0) &&  dist <= posOffset) || ( (dist < 0) && (dist >= negOffset)) ) {
	  rdCount++;
	  #print "Redundant: pos1 " pos1 " pos2 "pos2 " dist " dist;
	  break;
	}
	else
	  ;#print "Notredundant: pos1 " pos1 " pos2 "pos2 " dist " dist;
	  
      }
    }
  }
  print rdCount/siteNum;
#  print rdCount/s1SiteNum "\t" rdCount/s2SiteNum;
}
