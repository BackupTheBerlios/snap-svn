# This script takes as input an ordered  list of positions and creates a histogram for them.
# It is based on the theory of parzen Windows for aprametric probability disribution estimation.
# The size of the bins is Vn = 500/sqrt(n) where n is the number of samples
# and P_n(x) = 1/n * \sum_{i=1}^n 1/Vn \Phi(x_n - x) and Phi() is an indiator function which gets 1 if the the distance between the two points is no more then Vn/2 
# This means that for 10 samples you get bin sizes of ~150bp, for 100 samples we get bin sizes of 50bp.
# The first argument is the relevant field index (I), assuming tab seperation.
BEGIN {
  FS = "\t";
  I = ARGV[1];
  ARGV[1] = "";
  V1 = 1000;
  count = 0;
  totalCount = 0;
}
( FNR == 1 ) {
  firstPosition = $I;
  count++;
  totalCount++;
  sample[count] = $I;
  sampleCount[count]++;
  lastPosition = $I;
}
# skip empty lines
(FNR > 1 && $I != "" )  {
  totalCount++;
  if ( $I != lastPosition)
    count++;
  sample[count] = $I;
  sampleCount[count]++;
  lastPosition = $I;
}

END {
  # nothing is printed if this was an empty file
  if ( totalCount == 0)
    exit(0);
#  print "count " count " totalCount " totalCount ;
#  exit(1);
  if (firstPosition < -1000)
    firstPosition = -1000;
  if ( lastPosition <= -1 )
    lastPosition = -1;
  
  Vn = (totalCount > 0 ) ? int (V1/sqrt(totalCount)) : 0;  
  maxDist = Vn*1.0 / 2.0;
#  print "Vn "Vn" maxDist "maxDist;
#  exit(1);
  lastStartIndex = 1;
  for ( i = firstPosition;i<= lastPosition;i++) {
    currCount = 0;
    inRange = 0; # flag to indicate we got into the range of samples around our current point
    for (j = lastStartIndex;j<= count;j++) {
      dist = sqrt( (sample[j] - i) * (sample[j] - i));
      if (dist <= maxDist) {
	currCount += sampleCount[j];
	if (inRange == 0) {
	  inRange = 1;
	  lastStartIndex = j;
	}
      }
      # if we got out of range again then break scanning the rest of the points which are even more far..
      else if ( (dist > maxDist) && (inRange == 1))
	break;
    }
    P[i] = currCount*1.0/(Vn*totalCount);
    #unifCount += currCount;
    #P[i] /= (count*1.0);
#    C[i] = currCount;
  }
#  for ( i = 1;i<= count;i++) 
#    P[i] /= unifCount;
  #print the resulting histogram,:
  for ( i = firstPosition;i<= lastPosition;i++)
    #print sample[i]"\t"P[i];#"\t"C[i];
    print i"\t"P[i];#"\t"C[i];
}
