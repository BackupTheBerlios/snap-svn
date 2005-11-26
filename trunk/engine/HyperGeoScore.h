#ifndef _SeedSearcher_HyperGeoScore_h
#define _SeedSearcher_HyperGeoScore_h

#include "Cluster.h"
#include "SeedSearcher.h"
#include "HyperGeoCache.h"



struct HyperGeoScore {
   //
   // simple 'gene-count' hyper-geometric scoring
   class Simple : public SeedSearcher::ScoreFunction {
   public:
      Simple ( bool countWeights                      ,     
               const SeedSearcher::WeightFunction& wf ,
               const SequenceDB& allSequences         );

      virtual ~Simple () {
         delete _cache;
      }

      virtual double score (const Assignment& feature,
                           const Assignment& projection,
                           const SeqCluster& containingFeature, // k
                           SeedSearcher::ScoreParameters** parameters
                           );

     //
     // print the score parameters 
     virtual void writeAsText (Persistance::TextWriter&, 
                               const SeedSearcher::ScoreParameters*);

   private:
      bool _countWeights;
      SeqCluster _allSequences;// m
      SeqCluster _positivelyLabeled; // n
      HyperGeoCache* _cache;
      const SeedSearcher::WeightFunction& _wf;
   };




   //
   // simplified 'total-count' scoring: all seeds have the same length.
   class FixedTotalCount : public SeedSearcher::ScoreFunction {
   public:
      FixedTotalCount (int seedLength,
                     bool countWeights,
                     const SeqWeightFunction& wf,   // m
                     const SequenceDB& allSequences                  // n
                     );

      virtual ~FixedTotalCount () {
         delete _cache;
      }

      virtual double score (const Assignment& feature,
                           const Assignment& projection,
                           const SeqCluster& containingFeature, // k
                           SeedSearcher::ScoreParameters** parameters
                           );

     //
     // print the score parameters 
     virtual void writeAsText (Persistance::TextWriter&, 
                               const SeedSearcher::ScoreParameters*);

   private:
      bool _countWeights;
      SeqCluster _allSequences;     // m
      const SeqWeightFunction& _wf; // n
      HyperGeoCache* _cache;
   };


   //
   // 'total-count' scoring, which takes into account varying-length seeds
   class TotalCount : public SeedSearcher::ScoreFunction {
   public:
      TotalCount (bool countWeights,
                  const SequenceDB::Cluster& positivelyLabeled,   // m
                  const SequenceDB& allSequences                  // n
                 );

      virtual ~TotalCount () {
         delete _totalCache;
      }

      virtual double score (const Assignment& feature,
                           const Assignment& projection,
                           const SeqCluster& containingFeature, // k
                           SeedSearcher::ScoreParameters** parameters
                           );

     //
     // print the score parameters 
      virtual void writeAsText ( Persistance::TextWriter&, 
                                 const SeedSearcher::ScoreParameters*);

   private:
      bool _countWeights;
      SeqCluster _allSequences;     // m
      SeqCluster _positivelyLabeled; // n
      HyperGeoTotalCache* _totalCache;
   };
};



#endif // _SeedSearcher_HyperGeoScore_h










