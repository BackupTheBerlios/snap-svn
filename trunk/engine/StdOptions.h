#ifndef _SeedSearcher_StdOption_h
#define _SeedSearcher_StdOption_h

#include "SequenceDB.h"
#include "SeedSearcher.h"
#include "Assignment.h"

#include "HyperGeoCache.h"
#include "Core/AutoPtr.h"

#include "Persistance/Defs.h"
#include "Persistance/TextWriter.h"

class AlphabetCode;


//
// this header contains the standard definitions used for SeedSearcher
//

class HyperGeoScore : public SeedSearcher::ScoreFunction {
public:
   HyperGeoScore (bool countWeights,
                  const SequenceDB::Cluster& positivelyLabeled,   // m
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
   bool _countWeights;
   const SequenceDB& _allSequences;        // m
   SequenceDB::Cluster _positivelyLabeled; // n
   AutoPtr <HyperGeoCache> _cache;
};


class ACGTAlphabet {
   //
   // this class defines the basic ACGT alphabet
public:
   static const AlphabetCode& get ();
   static int cardinality () {
      return 5; // includes the 'N' character
   }
   static int assgCardinality () {
      return 4; // does not includes the 'N' character
   }
};

class ACGTWriter : public Assignment::Writer{
public:
   virtual ~ACGTWriter () {
   }

   virtual void write (const Assignment::Position&, Persistance::TextWriter& out);
};

class ACGTPosition : public Assignment::Position {
public:
   ACGTPosition (Assignment::Strategy s) 
   : Position (Assignment::all, ACGTAlphabet::assgCardinality (), s) {
      index (4, false); // turn off the 'N' position
   }
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
                     double score) {
      return _next->add (assg, cluster, score);
   }

   virtual int size () const {
      return _next->size ();
   }

   virtual const SeedSearcher::Feature& get (int index) const {
      return _next->get (index);
   }

protected:
   SeedSearcher::BestFeatures* _next;
};




class KBestFeatures : public SeedSearcher::BestFeatures {
   //
   // this class is intended to maintain a buffer of the K-best
   // features found.
public:
   KBestFeatures (int k, int maxRedundancyOffset);
   virtual ~KBestFeatures ();

   //
   // takes ownership of Assignment & Cluster
   virtual bool add (AutoPtr <Assignment>,
                     AutoPtr <SequenceDB::Cluster>,
                     double score);

   virtual int size () const {
      return _size;
   }

   virtual const SeedSearcher::Feature& get (int index) const {
      debug_mustbe (index >= 0);
      debug_mustbe (index < _size);
      return _features [index];
   }

private:
   int _k;
   int _size;
   int _maxRedundancyOffset;
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
                  bool isPercent);

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

   //
   // returns the minimum positive sequences that should contain a feature
   // if it is to be considered 'good'
   int minPositiveSequences () const {
      return _minPositiveSeqs;
   }



private:
   double _minScore;
   int _minPositiveSeqs;
   SequenceDB::Cluster _posSeqs;
};

#endif // _SeedSearcher_StdOption_h
