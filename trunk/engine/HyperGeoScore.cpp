//
// File        : $RCSfile: $ 
//               $Workfile: HyperGeoScore.cpp $
// Version     : $Revision: 16 $ 
//               $Author: Aviad $
//               $Date: 27/08/04 2:08 $ 
// Description :
//    Concrete Score function classes - 
//      based on Hyper-Geometric distribution
//
// Author: 
//    Aviad Rozenhek (mailto:aviadr@cs.huji.ac.il) 2003-2004
//
// written for the SeedSearcher program. 
// for details see www.huji.ac.il/~hoan 
// and also http://www.cs.huji.ac.il/~nirf/Abstracts/BGF1.html
//
// this file and as well as its library are released for academic research 
// only. the LESSER GENERAL PUBLIC LICENSE (LPGL) license
// as well as any other restrictions as posed by the computational biology lab
// and the library authors appliy.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "Assignment.h"
#include "HyperGeoScore.h"
#include "legacy/MathPlus.h"



//
// Simple
//

HyperGeoScore::Simple::Simple (
                       bool countWeights,
                       const SeqWeightFunction& wf ,
                       const SequenceDB& allSequences // m
                      )
:  _countWeights (countWeights),
   _allSequences (allSequences),
   _positivelyLabeled (_allSequences, wf),
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

double HyperGeoScore::Simple::log2score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature,// k
                     ScoreParameters** parameters
                     ) const
{
   //
   // check if we are counting the weights of all sequences
   // or just the amount of sequences
   int posCount;
   int containingCount;
   if (_countWeights) {
      SeqCluster::SumSeqWeights posWeightCount;
      SeqCluster::SumSeqWeights negWeightCount;
      containingFeature.performDivided (_wf, posWeightCount, negWeightCount);

      posCount = ROUND (posWeightCount.result ());
      containingCount = ROUND (negWeightCount.result () + posCount);
   }
   else {
      //
      // 
      SeqCluster::CountSequences posCountPred;
      SeqCluster::CountSequences negCountPred;
      containingFeature.performDivided (_wf, posCountPred, negCountPred);

      posCount = posCountPred.result ();
      containingCount = negCountPred.result () + posCount;
   }

   return _cache->log2Tail (posCount, containingCount, parameters);
}

//
// print the score parameters 
void HyperGeoScore::Simple::writeAsText (Persistance::TextWriter& writer, 
                         const ScoreParameters* params) const
{
   _cache->writeAsText (writer, params);
}




//
// FixedTotalCount
//


HyperGeoScore::FixedTotalCount::FixedTotalCount (int seedLength,
                             bool countWeights,
                              const SeqWeightFunction& wf,// n
                              const SequenceDB& allSequences // m
               )
:  _countWeights (countWeights),
   _allSequences (allSequences),
   _wf (wf)
{
   int n;
   int m;
   if (_countWeights) {
      SeqCluster::MaxPosWeightsNoOverlaps pos (seedLength);
      SeqCluster::MaxPosWeightsNoOverlaps neg (seedLength);
      _allSequences.performDivided (wf, pos, neg);

      n = ROUND (pos.result ());
      m = ROUND (neg.result () + pos.result ());
   }
   else {
      SeqCluster::MaxPosNoOverlaps pos (seedLength);
      SeqCluster::MaxPosNoOverlaps neg (seedLength);
      _allSequences.performDivided (wf, pos, neg);

      n = ROUND (pos.result ());
      m = ROUND (pos.result () + neg.result ());
   }

   _cache = new HyperGeoCache (n, m);
}


double HyperGeoScore::FixedTotalCount::log2score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature,// k
                     ScoreParameters** parameters
                     ) const
{
   //
   // check if we are counting the weights of all sequences
   // or just the amount of sequences
   int posCount;
   int containingCount;
   if (_countWeights) {
      SeqCluster::SumPosWeights pos;
      SeqCluster::SumPosWeights neg;
      containingFeature.performDivided (_wf, pos, neg);

      posCount = ROUND (pos.result ());
      containingCount = ROUND (pos.result () + neg.result ());
   }
   else {
      SeqCluster::CountPositions pos;
      SeqCluster::CountPositions neg;
      containingFeature.performDivided (_wf, pos, neg);
      
      posCount = ROUND (pos.result ());
      containingCount = ROUND (pos.result () + neg.result ());
   }

   return _cache->log2Tail (posCount, containingCount, parameters);
}

//
// print the score parameters 
void HyperGeoScore::FixedTotalCount::writeAsText (Persistance::TextWriter& writer, 
                         const ScoreParameters* params) const
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


double HyperGeoScore::TotalCount::log2score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature,// k
                     ScoreParameters** parameters
                     ) const
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

   return _totalCache->log2Tail (posCount, containingCount, n, m, parameters);
}

//
// print the score parameters 
void HyperGeoScore::TotalCount::writeAsText (Persistance::TextWriter& writer, 
                         const ScoreParameters* params) const
{
   _totalCache->writeAsText (writer, params);
}



















