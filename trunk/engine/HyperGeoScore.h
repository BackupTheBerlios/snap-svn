#ifndef _SeedSearcher_HyperGeoScore_h
#define _SeedSearcher_HyperGeoScore_h

#include "SeedSearcher.h"
#include "HyperGeoCache.h"



class HyperGeoScore : public SeedSearcher::ScoreFunction {
public:
   HyperGeoScore (const SequenceDB::Cluster& positivelyLabeled,   // m
                  const SequenceDB& allSequences                  // n
                  );

   virtual ~HyperGeoScore () {
   }
/*
   virtual double score (PrefixTreePreprocessor::GenePositions& , // ?
   Assignment* optTargetAssignment = NULL,
   bool* outWorthwhileHint = NULL)
   */
  virtual double score (const Assignment& feature,
                        const Assignment& projection,
                        const SequenceDB::Cluster& containingFeature// k
                        );

private:
   const SequenceDB& _allSequences;        // m
   SequenceDB::Cluster _positivelyLabeled; // n
   AutoPtr <HyperGeoCache> _cache;
};



class ACGTAlphabet {
   //
   // this class defines the basic ACGT alphabet
public:
   static const AlphabetCode& get ();
};





class BestFeaturesLink : public SeedSearcher::BestFeatures {
   //
   // this class is the base class of all BestFeatures classes
   // that do only partial processing of a feature, before passing
   // the feature along to the next BestFeatures link
public:
   BestFeaturesLink (SeedSearcher::BestFeatures* next) : _next (next) {
   }
   virtual bool add (AutoPtr <Assignment> assg,
                     AutoPtr <SequenceDB::Cluster> cluster,
                     double score) = 0 {
      return _next->add (assg, cluster, score);
   }

protected:
   SeedSearcher::BestFeatures* _next;
};




class KBestFeatures : public SeedSearcher::BestFeatures {
   //
   // this class is intended to maintain a buffer of the K-best
   // features found.
public:
   KBestFeatures (int k);
   virtual ~KBestFeatures ();

   //
   // takes ownership of Assignment & Cluster
   virtual bool add (AutoPtr <Assignment>,
                     AutoPtr <SequenceDB::Cluster>,
                     double score);
private:
   int _k;
   int _size;
   SeedSearcher::Feature* _features;
};





class GoodFeatures : public BestFeaturesLink {
   //
   // this class is intended to allow only features that
   // are good enough - (1) have a score high enough
   //                   (2) are present in at least k positive sequences
   //                   (3) are presnt in at least n percent of positive sequences
public:
   GoodFeatures (SeedSearcher::BestFeatures* next, 
                  const SequenceDB::Cluster& posSeqs,
                  double minScore, 
                  int minPos, 
                  int minPosPercent);

   //
   // takes ownership of Assignment & Cluster
   virtual bool add (AutoPtr <Assignment>,
                     AutoPtr <SequenceDB::Cluster>,
                     double score);

private:
   double _minScore;
   int _minPositiveSeqs;
   int _minPositiveSeqsPercent;
   SequenceDB::Cluster _posSeqs;
};

#endif // _SeedSearcher_HyperGeoScore_h