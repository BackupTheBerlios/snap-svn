#include "HyperGeoScore.h"
#include "Legacy/mathplus.h"


//
// Simple
//

HyperGeoScore::Simple::Simple (
                       bool countWeights,
                       const SequenceDB::Cluster& positivelyLabeled,// n
                       const SequenceDB& allSequences // m
                      )
:  _countWeights (countWeights),
   _allSequences (allSequences),
   _positivelyLabeled (positivelyLabeled)
{
   if (!_countWeights) {
      _cache = 
         new HyperGeoCache (positivelyLabeled.size (), 
                            _allSequences.size ());
   }
   else {
      _cache = 
         new HyperGeoCache (ROUND (positivelyLabeled.sumAbsWeights ()), 
                            ROUND (_allSequences.sumAbsWeights ()));
   }
}


double HyperGeoScore::Simple::score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature// k
                     )
{
   //
   // TODO: mustbe some easier way...
   SequenceDB::Cluster positiveContaining;
   SequenceDB::Cluster::intersect ( _positivelyLabeled,
                                    containingFeature,
                                    positiveContaining);

   //
   // otherwise its just a waste of time...
   debug_mustbe (positiveContaining.size () > 0);

   //
   // check if we are counting the weights of all sequences
   // or just the amount of sequences
   int posCount;
   int containingCount;
   if (_countWeights) {
      double posWeightCount = positiveContaining.sumAbsWeights ();
      posCount = ROUND (posWeightCount);

      //
      // sums the weights only of weighted sequences.
      double containingWeightCount = containingFeature.sumAbsWeights ();
      containingCount = ROUND (containingWeightCount);
   }
   else {
      //
      // 
      posCount = positiveContaining.size();
      containingCount = containingFeature.size();
   }

   return _cache->logTail (posCount, containingCount);
}




//
// FixedTotalCount
//


HyperGeoScore::FixedTotalCount::FixedTotalCount (int seedLength,
                             bool countWeights,
                              const SequenceDB::Cluster& positivelyLabeled,// n
                              const SequenceDB& allSequences // m
               )
:  _countWeights (countWeights),
   _allSequences (allSequences),
   _positivelyLabeled (positivelyLabeled)
{
   int n;
   int m;
   if (_countWeights) {
      n = ROUND (_positivelyLabeled.maxPositionsAbsWeightsNoOverlaps (seedLength));
      m = ROUND (_allSequences.maxPositionsAbsWeightsNoOverlaps (seedLength));
   }
   else {
      n = _positivelyLabeled.maxPositionsNoOverlaps (seedLength);
      m = _allSequences.maxPositionsNoOverlaps (seedLength);
   }

   _cache = new HyperGeoCache (n, m);
}


double HyperGeoScore::FixedTotalCount::score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature// k
                     )
{
   //
   // TODO: mustbe some easier way...
   SequenceDB::Cluster positiveContaining;
   SequenceDB::Cluster::intersect ( _positivelyLabeled,
                                    containingFeature,
                                    positiveContaining);

   //
   // otherwise its just a waste of time...
   debug_mustbe (positiveContaining.size () > 0);

   positiveContaining.importPositions (containingFeature);

   //
   // check if we are counting the weights of all sequences
   // or just the amount of sequences
   int posCount;
   int containingCount;
   if (_countWeights) {
      double posWeightCount = positiveContaining.sumPositionAbsWeights ();
      posCount = ROUND (posWeightCount);

      //
      // sums the weights only of weighted sequences.
      double containingWeightCount = containingFeature.sumPositionAbsWeights ();
      containingCount = ROUND (containingWeightCount);
   }
   else {
      //
      // 
      posCount = positiveContaining.countPositions ();
      containingCount = containingFeature.countPositions ();
   }

   return _cache->logTail (posCount, containingCount);
}


//
//
// TotalCount

HyperGeoScore::TotalCount::TotalCount (
                             bool countWeights,
                              const SequenceDB::Cluster& positivelyLabeled,// n
                              const SequenceDB& allSequences // m
               )
:  _countWeights (countWeights),
   _allSequences (allSequences),
   _positivelyLabeled (positivelyLabeled)
{
   //
   // 
   _totalCache = new HyperGeoTotalCache;
}


double HyperGeoScore::TotalCount::score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature// k
                     )
{
   //
   // TODO: mustbe some easier way...
   SequenceDB::Cluster positiveContaining;
   SequenceDB::Cluster::intersect ( _positivelyLabeled,
                                    containingFeature,
                                    positiveContaining);

   //
   // otherwise its just a waste of time...
   debug_mustbe (positiveContaining.size () > 0);

   positiveContaining.importPositions (containingFeature);

   //
   // check if we are counting the weights of all sequences
   // or just the amount of sequences
   int posCount;
   int containingCount;
   if (_countWeights) {
      double posWeightCount = positiveContaining.sumPositionAbsWeights ();
      posCount = ROUND (posWeightCount);

      //
      // sums the weights only of weighted sequences.
      double containingWeightCount = containingFeature.sumPositionAbsWeights ();
      containingCount = ROUND (containingWeightCount);
   }
   else {
      //
      // 
      posCount = positiveContaining.countPositions ();
      containingCount = containingFeature.countPositions ();   
   }

   int n;
   int m;
   if (_countWeights) {
      n = ROUND (_positivelyLabeled.maxPositionsAbsWeightsNoOverlaps (feature.length ()));
      m = ROUND (_allSequences.maxPositionsAbsWeightsNoOverlaps (feature.length ()));
   }
   else {
      n = _positivelyLabeled.maxPositionsNoOverlaps (feature.length ());
      m = _allSequences.maxPositionsNoOverlaps (feature.length ());
   }

   return _totalCache->logTail (posCount, containingCount, n, m);
}








