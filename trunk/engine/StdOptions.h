#ifndef _SeedSearcher_StdOption_h
#define _SeedSearcher_StdOption_h

#include "Defs.h"
#include "SequenceDB.h"
#include "SeedSearcher.h"
#include "AssignmentFormat.h"

#include "HyperGeoCache.h"
#include "Core/AutoPtr.h"

#include "Persistance/Defs.h"
#include "Persistance/TextWriter.h"


//
// this header contains the standard definitions used for SeedSearcher
//




class ACGTAlphabet {
   //
   // this class defines the basic ACGT alphabet
public:
   static const AlphabetCode& get (bool cardinalityIncludesN);
   static int cardinality () {
      return 5; // includes the 'N' character
   }
   static int assgCardinality () {
      return 4; // does not includes the 'N' character
   }
};

class ACGTWriter : public AssignmentWriter{
public:
   virtual ~ACGTWriter () {
   }

   virtual void write (const Assignment::Position&, Persistance::TextWriter& out) const ;
};

class ACGTPosition : public Assignment::Position {
public:
   ACGTPosition (Assignment::Strategy s) 
   : Position (Assignment::all, ACGTAlphabet::assgCardinality (), s) {
      index (4, false); // turn off the 'N' position
   }
};




//
//
class SimpleWeightFunction : public SeqWeightFunction {
public:
   SimpleWeightFunction (double inThreshold) : _threshold (inThreshold) {
   }
   virtual ~SimpleWeightFunction () {
   }
   //
   // returns true iff the weight belongs to the positive or negative set.
   // if so, 'outIsPositive' is set to true iff the weight belongs to the
   // positive set.
   virtual bool isRelevantImpl (double weight, bool& outIsPositive) const {
      outIsPositive = weight >= _threshold;
      return true;
   }

protected:
   double _threshold;
};


//
//
class BestFeaturesLink : public SeedSearcher::BestFeatures {
   //
   // this class is the base class of all BestFeatures classes
   // that do only partial processing of a feature, before passing
   // the feature along to the next BestFeatures link
public:
   BestFeaturesLink (SeedSearcher::BestFeatures* next) : _next (next) {
   }
   virtual bool add (SeedSearcher::Feature_var feature) {
      return _next->add (feature);
   }

   virtual int size () const {
      return _next->size ();
   }

   virtual const SeedSearcher::Feature& get (int index) const {
      return _next->get (index);
   }

   virtual bool isSorted () const {
      return _next->isSorted ();
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
   virtual bool add (SeedSearcher::Feature_var feature);

   virtual int size () const {
      return _size;
   }

   virtual const SeedSearcher::Feature& get (int index) const {
      debug_mustbe (index >= 0);
      debug_mustbe (index < _size);
      return _features [index];
   }

   bool isSorted () const {
      return _sorted;
   }
   void sort ();

private:
   int _k;
   int _size;
   int _maxRedundancyOffset;
   SeedSearcher::Feature* _features;
   bool _sorted;
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
   virtual bool add (SeedSearcher::Feature_var feature);

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

struct StatFix {
   //
   // given a list of features with decreasing scores (best ones first)
   // and a significant cut-off P (all bigger than P are siginificant)
   // returns the largest index K (1 based), whose value is still bigger than P*K/N.
   //
   // if no feature fits, returns 0
   // TODO: is this correct?
   static int FDR (SeedSearcher::BestFeatures&, int N, double P);

   //
   // given a list of features with decreasing scores (best ones first)
   // and a significant cut-off P (all bigger than P are siginificant)
   // returns the largest index K (1 based), whose value is still bigger than P/N.
   //
   // if no feature fits, returns 0
   // TODO: is this correct?
   static int bonferroni (SeedSearcher::BestFeatures&, int N, double P);
};

#endif // _SeedSearcher_StdOption_h








