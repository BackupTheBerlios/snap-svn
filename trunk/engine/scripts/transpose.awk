#! /usr/bin/awk -f
# This script is used to transpose a matrix,
# assumed to be tab delimited, and all the rows are assumed to be of the same length

BEGIN {
  FS = "\t";
  rowNum = 0;
}
( FNR == 1 ) {
  colNum = NF;
}
(NF > 0 ) {
  rowNum++;
  if (NF != colNum) {
    print "ERROR - line " FNR " has only " NF " columns, compared to " colNum;
    #exit(1);
  }
  for (j =1;j<=NF;j++) {
    val[FNR,j] = $j;
  }
}

END {
#  print rowNum"\t"colNum;
  for (j = 1;j<=colNum;j++) {
    for (i = 1;i<rowNum;i++)
      printf("%s\t",val[i,j]);
    printf("%s\n",val[rowNum,j]);
  }	     
}
