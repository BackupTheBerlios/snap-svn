#ifndef _SeedSearcher_HyperGeoScore_h
#define _SeedSearcher_HyperGeoScore_h

//
// File        : $RCSfile: $ 
//               $Workfile: HyperGeoScore.h $
// Version     : $Revision: 12 $ 
//               $Author: Aviad $
//               $Date: 16/12/04 6:18 $ 
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

#include "Cluster.h"
#include "SeedSearcher.h"
#include "HyperGeoCache.h"



struct HyperGeoScore {
   //
   // simple 'gene-count' hyper-geometric scoring
   class Simple : public ScoreFunction {
   public:
      Simple ( bool countWeights                      ,     
               const SeqWeightFunction& wf ,
               const SequenceDB& allSequences         );

      virtual ~Simple () {
         delete _cache;
      }

      virtual double log2score (const Assignment& feature,
                           const Assignment& projection,
                           const SeqCluster& containingFeature, // k
                           ScoreParameters** parameters
                           ) const;

     //
     // print the score parameters 
     virtual void writeAsText (Persistance::TextWriter&, 
                               const ScoreParameters*) const;

   private:
      bool _countWeights;
      SeqCluster _allSequences;// m
      SeqCluster _positivelyLabeled; // n
      HyperGeoCache* _cache;
      const SeqWeightFunction& _wf;
   };




   //
   // simplified 'total-count' scoring: all seeds have the same length.
   class FixedTotalCount : public ScoreFunction {
   public:
      FixedTotalCount (int seedLength,
                     bool countWeights,
                     const SeqWeightFunction& wf,   // m
                     const SequenceDB& allSequences                  // n
                     );

      virtual ~FixedTotalCount () {
         delete _cache;
      }

      virtual double log2score (const Assignment& feature,
                           const Assignment& projection,
                           const SeqCluster& containingFeature, // k
                           ScoreParameters** parameters
                           ) const;

     //
     // print the score parameters 
     virtual void writeAsText (Persistance::TextWriter&, 
                               const ScoreParameters*) const;

   private:
      int _seedLength;
      bool _countWeights;
      SeqCluster _allSequences;     // m
      const SeqWeightFunction& _wf; // n
      HyperGeoCache* _cache;
   };
};



#endif // _SeedSearcher_HyperGeoScore_h











