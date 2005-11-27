//
// File        : $RCSfile: $ 
//               $Workfile: HyperGeoScore.cpp $
// Version     : $Revision: 18 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:46 $ 
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
// M = count for all sequences
// N = count for all positive sequences
// k = count for all sequences that contain the seed
// x = count for all posive sequences that contain the seed


//
// Simple: 
//    Gene-counts
//       M = total number of sequences
//       N = total number of positive sequences
//       x = total number of sequences that contain the seed
//       k = total number of positive sequences that contain the seed
//
//    Gene-partial-counts
//       M = total number of sequences
//       N = total sum of weights of all sequences
//       k = total number of sequences that contain the seed
//       x = total sum of weights of sequences that contain the seed
//
//
//    Gene-hot-spot-count
//       M = total number of sequences
//       N = total sum of (expected) weights of all sequences
//       k = total number of sequences that contain the seed
//       x = total sum on sequences 's' of max(weight(p)) 
//             for all positions 'p' in 's'

HyperGeoScore::Simple::Simple (
                       PositionWeightType positionWeightType,
                       const SeqWeightFunction& wf,
                       const SequenceDB& allSequences // m
                      )
:  _positionWeightType (positionWeightType),
   _wf (wf)
{
   int N = 0;
   const int M = wf.getWeightDB().size();
   switch (_positionWeightType) {
      case _position_weight_discrete_: {
         SeqWeightFunction::CIterator it (wf.iterator ());
         for (; it.hasNext() ; it.next ()) {
            if (wf.isPositive (it->first))
               ++N;
         }
      }
      break;

      case _position_weight_hotspots_: 
      case _position_weight_real_:{
         double DN = 0;
         SeqWeightFunction::CIterator it (wf.iterator ());
         for (; it.hasNext() ; it.next ()) {
            DN += wf.weight (it->first);
         }
         N = ROUND (DN);
      }
      break;
      default: mustfail (); 
         break;
   };

   _cache = new HyperGeoCache (ROUND (N), M);
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
   int posCount = 0;
   const int containingCount = containingFeature.size ();
   switch (_positionWeightType) {
      case _position_weight_discrete_: {
         SeqCluster::CountSequences posCountPred;
         containingFeature.performOnPositives(_wf, posCountPred);
         posCount = posCountPred.result ();
      }
      break;

      case _position_weight_real_: {
         SeqCluster::SumSeqWeights posWeightCount (_wf);
         containingFeature.perform (posWeightCount);
         posCount = ROUND (posWeightCount.result ());
      }
      break;

      case _position_weight_hotspots_: {
         SeqCluster::SumMaxPositionalWeight posCountPred (_wf, feature.length());
         containingFeature.perform (posCountPred);
         posCount = ROUND (posCountPred.result ());
      }
      break;
      default: mustfail (); 
         break;
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
// FixedTotalCount:
//    Total-counts
//       M = for all sequences s: sum-of (s->length / seed-length)
//       N = for all positive sequences s: sum-of (s->length / seed-length)
//       x = total number of positions of the seed (without overlaps)
//       k = total number of positive positions of the seed (without overlaps)
//
//    Total-partial-counts
//       M = for all sequences s: sum-of (s->length / seed-length)
//       N = for all sequences s: sum-of (s->weight * s->length / seed-length)
//       k = total number of positions of the seed (without overlaps)
//       x = for all seed position p (without overlaps): sum-of (p->weight)
//
//    Total-hot-spots-count
//       M = for all sequences s: sum-of (s->length / seed-length)
//       N = for all sequences s: sum-of (s->expected_weight * s->length / seed-length)
//       k = total number of positions of the seed (without overlaps)
//       x = for all seed position p (without overlaps): sum-of (p->weight)

HyperGeoScore::FixedTotalCount::FixedTotalCount (int seedLength,
                             PositionWeightType positionWeightType ,
                              const SeqWeightFunction& wf,// n
                              const SequenceDB& allSequences // m
               )
:  _seedLength (seedLength),
   _positionWeightType (positionWeightType),
   _wf (wf)
{
   int n = 0;
   int m = 0;
   SeqCluster dbcluster (allSequences);

   switch (_positionWeightType) {
      case _position_weight_discrete_:  {
         SeqCluster::MaxPosNoOverlaps pos (_seedLength);
         SeqCluster::MaxPosNoOverlaps neg (_seedLength);
         dbcluster.performDivided (wf, pos, neg);

         n = ROUND (pos.result ());
         m = ROUND (pos.result () + neg.result ());
      }
      break;

      case _position_weight_real_: 
      case _position_weight_hotspots_: {
         SeqCluster::MaxPosNoOverlaps DM (seedLength);
         SeqCluster::WeightedMaxPosNoOverlaps DN (_wf, seedLength);
         SeqCluster::Compose< 
            SeqCluster::MaxPosNoOverlaps,
            SeqCluster::WeightedMaxPosNoOverlaps> op (DM, DN);

         dbcluster.perform (op);

         m = ROUND (DM.result());
         n = ROUND ((DN.result()));
      }
      break;
      default: mustfail (); 
         break;
   }
   _cache = new HyperGeoCache (n, m);
}


double HyperGeoScore::FixedTotalCount::log2score (const Assignment& feature,
                     const Assignment& projection,
                     const SequenceDB::Cluster& containingFeature,// k
                     ScoreParameters** parameters
                     ) const
{
   debug_mustbe (feature.length () == _seedLength);
   //
   // check if we are counting the weights of all sequences
   // or just the amount of sequences
   int posCount = 0;
   int containingCount = 0;
   switch (_positionWeightType) {
      case _position_weight_discrete_:      {
         //
         // this also removes overlaps
         SeqCluster::CountPositionsNoOverlaps pos (_seedLength);
         SeqCluster::CountPositionsNoOverlaps neg (_seedLength);
         containingFeature.performDivided (_wf, pos, neg);

         posCount = ROUND (pos.result ());
         containingCount = ROUND (pos.result () + neg.result ());
      }
      break;

      case _position_weight_real_:      {
         SeqCluster::CountPositionsNoOverlaps dContaining (_seedLength);
         SeqCluster::SumPosWeights dPos (_wf, _seedLength);
         SeqCluster::Compose< 
            SeqCluster::CountPositionsNoOverlaps,
            SeqCluster::SumPosWeights> op (dContaining, dPos);
         containingFeature.perform (op);

         posCount = ROUND (dPos.result ());
         containingCount = ROUND (dContaining.result());
      }
      break;
      case _position_weight_hotspots_:      {
         SeqCluster::CountPositionsNoOverlaps dContaining (_seedLength);
         SeqCluster::SumPositionalWeightNoOverlaps dPos (_wf, _seedLength);
         SeqCluster::Compose< 
            SeqCluster::CountPositionsNoOverlaps,
            SeqCluster::SumPositionalWeightNoOverlaps> op (dContaining, dPos);
         containingFeature.perform (op);

         posCount = ROUND (dPos.result ());
         containingCount = ROUND (dContaining.result());
      }
      break;
      default: mustfail (); 
         break;
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











