#include "HyperGeoScore.h"
#include "Legacy/mathplus.h"



//
// Simple
//

HyperGeoScore::Simple::Simple (
                       bool countWeights,
                       const SeedSearcher::WeightFunction& wf ,
                       const SequenceDB& allSequences // m
                      )
:  _countWeights (countWeights),
   _allSequences (allSequences),
   _positivelyLabeled (allSequences, wf),
   _wf (wf)
{
   if (!_countWeights) {
      _cache = 
         new HyperGeoCache (_positivelyLabeled.size (), 
                            _allSequences.size ());
   }
   else {
      _cache = 
         new HyperGeoCache (ROUND (_positivelyLabeled.sumAbsWeights ()), 
                            ROUND (_allSequences.sumAbsWeights ()));
   }
}

double HyperGeoScore::Simple::score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature,// k
                     SeedSearcher::ScoreParameters** parameters
                     )
{
/*
   //
   // TODO: mustbe some easier way...
   SequenceDB::Cluster positiveContaining;
   SequenceDB::Cluster::intersect ( _positivelyLabeled,
                                    containingFeature,
                                    positiveContaining);
*/

   //
   // otherwise its just a waste of time...
   //debug_mustbe (positiveContaining.size () > 0);

   //
   // check if we are counting the weights of all sequences
   // or just the amount of sequences
   int posCount;
   int containingCount;
   if (_countWeights) {
      SeqCluster::SumWeights posWeightCount;
      SeqCluster::SumWeights negWeightCount;
      containingFeature.perform (_wf, posWeightCount, negWeightCount);

      posCount = posWeightCount.result ();
      containingCount = negWeightCount.result () + posCount;

   /*
      double posWeightCount = positiveContaining.sumAbsWeights ();
      posCount = ROUND (posWeightCount);

      //
      // sums the weights only of weighted sequences.
      double containingWeightCount = containingFeature.sumAbsWeights ();
      containingCount = ROUND (containingWeightCount);
      */
   }
   else {
      //
      // 
      SeqCluster::CountSequences posCountPred;
      SeqCluster::CountSequences negCountPred;
      containingFeature.perform (_wf, posCountPred, negCountPred);

      posCount = posCountPred.result ();
      containingCount = negCountPred.result () + posCount;
/*
      posCount = positiveContaining.size();
      containingCount = containingFeature.size();
*/
   }

   return _cache->logTail (posCount, containingCount, parameters);
}

//
// print the score parameters 
void HyperGeoScore::Simple::writeAsText (Persistance::TextWriter& writer, 
                         const SeedSearcher::ScoreParameters* params)
{
   _cache->writeAsText (writer, params);
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
                     const SequenceDB::Cluster& containingFeature,// k
                     SeedSearcher::ScoreParameters** parameters
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
//   debug_mustbe (positiveContaining.size () > 0);

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

   return _cache->logTail (posCount, containingCount, parameters);
}

//
// print the score parameters 
void HyperGeoScore::FixedTotalCount::writeAsText (Persistance::TextWriter& writer, 
                         const SeedSearcher::ScoreParameters* params)
{
   _cache->writeAsText (writer, params);
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
                     const SequenceDB::Cluster& containingFeature,// k
                     SeedSearcher::ScoreParameters** parameters
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

   return _totalCache->logTail (posCount, containingCount, n, m, parameters);
}

//
// print the score parameters 
void HyperGeoScore::TotalCount::writeAsText (Persistance::TextWriter& writer, 
                         const SeedSearcher::ScoreParameters* params)
{
   _totalCache->writeAsText (writer, params);
}















