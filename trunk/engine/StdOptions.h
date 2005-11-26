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


class ACGTLangauge : public Langauge{
   //
   // this class defines the ACGT langauge
public:
   enum {
      ACode = 0x1,
      CCode = 0x2,
      GCode = 0x4,
      TCode = 0x8,
   };
   ACGTLangauge () : _includeN (false) {
   }
   virtual ~ACGTLangauge () {
   }

   //
   // convert assignment position to text,
   // used to display search results
   virtual void write (const Assignment::Position&, Persistance::TextWriter& out) const ;

   //
   // returns the complement of an assignemnt 
   // (for instance the reverse assignment for ACGT langugaue)
   virtual void complement (const Assignment&, Assignment&) const;
   virtual void complement (const Str&, StrBuffer) const;

   //
   // return a wildcard with the appropriate strategy (for searching)
   virtual Assignment::Position wildcard (Assignment::Strategy s) const {
      return Assignment::Position (Assignment::all, cardinality (), s);
   }

   //
   // return the code of the langauge
   virtual const AlphabetCode& code () const {
      return getCode (_includeN);
   }
   //
   // get the cardinality of the alphabet 
   // (depends on inclusion of 'N' in alphabet)
   int cardinality () const{
      return _includeN? 5 : 4;
   }
   bool includeN () const {
      return _includeN;
   }
   void includeN (bool i) {
      _includeN = i;
   }
   
   //
   // 
   static const AlphabetCode& getCode (bool cardinalityIncludesN);

protected:
   //
   // if true includes the char 'N' in the langauge
   bool _includeN;
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
class IntervalWeightFunction : public SeqWeightFunction {
public:
   IntervalWeightFunction (double lo, double hi) : _hi (hi), _lo (lo) {
   }
   virtual ~IntervalWeightFunction () {
   }
   //
   // returns true iff the weight belongs to the positive or negative set.
   // if so, 'outIsPositive' is set to true iff the weight belongs to the
   // positive set.
   virtual bool isRelevantImpl (double weight, bool& outIsPositive) const {
      outIsPositive = (weight >= _lo) && (weight <= _hi);
      return true;
   }

protected:
   double _hi;
   double _lo;
};


//
//
class BorderWeightFunction : public SeqWeightFunction {
public:
   BorderWeightFunction (double lo, double hi) : _hi (hi), _lo (lo) {
   }
   virtual ~BorderWeightFunction () {
   }
   //
   // returns true iff the weight belongs to the positive or negative set.
   // if so, 'outIsPositive' is set to true iff the weight belongs to the
   // positive set.
   virtual bool isRelevantImpl (double weight, bool& outIsPositive) const {
      if (weight >= _hi) {
         outIsPositive = true;
         return true;
      }
      else if (weight <= _lo) {
         outIsPositive = false;
         return true;
      }

      return false;
   }

protected:
   double _hi;
   double _lo;
};


//
//
class BestFeaturesLink : public SeedSearcher::BestFeatures {
   //
   // this class is the base class of all BestFeatures classes
   // that do only partial processing of a feature, before passing
   // the feature along to the next BestFeatures link
public:
   BestFeaturesLink (SeedSearcher::BestFeatures* next, bool owner) 
   : _owner (owner), _next (next) {
   }
   virtual ~BestFeaturesLink () {
      if (_owner)
         delete _next;
   }
   virtual bool add (Feature_var feature) {
      return _next->add (feature);
   }

   virtual int size () const {
      return _next->size ();
   }

   virtual const Feature& get (int index) const {
      return _next->get (index);
   }
   virtual Feature& get (int index) {
      return _next->get (index);
   }

   virtual bool isSorted () const {
      return _next->isSorted ();
   }
   virtual void sort () {
      _next->sort ();
   }

protected:
   bool _owner;
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
   virtual bool add (Feature_var feature);

   virtual int size () const {
      return _size;
   }

   virtual const Feature& get (int index) const {
      debug_mustbe (index >= 0);
      debug_mustbe (index < _size);
      return _features [index];
   }
   virtual Feature& get (int index) {
      debug_mustbe (index >= 0);
      debug_mustbe (index < _size);
      return _features [index];
   }

   bool isSorted () const {
      return _sorted;
   }
   void sort ();

protected:
   virtual bool checkRedundancy (int index, const Assignment&);
   bool checkSimilarity (const Assignment&, const Assignment&);
   static bool checkSimilarity (int, const Assignment&, const Assignment&);

protected:
   int _k;
   int _size;
   int _maxRedundancyOffset;
   Feature* _features;
   bool _sorted;
};


//
//
class KBestFeaturesComplement : public KBestFeatures {
public:
   KBestFeaturesComplement (  int k, int maxRedundancyOffset, 
                              const Langauge& langauge)
   :  KBestFeatures (k, maxRedundancyOffset), _langauge (langauge)
   {
   }
   virtual ~KBestFeaturesComplement () {
   }

   virtual bool checkRedundancy (int index, const Assignment& assg) {
      //
      // check regular similarity
      if (checkSimilarity (_features [index].assignment (), assg))
         return true;

      //
      // check similarity with reverse
      return checkSimilarity (
         _features [index].complement (_langauge), assg);
   }

protected:
   const Langauge& _langauge; 
};



class GoodFeatures : public BestFeaturesLink {
   //
   // this class is intended to allow only features that
   // are good enough - (1) have a score high enough
   //                   (2) are present in at least k positive sequences
   //                   (3) are presnt in at least n percent of positive sequences
public:
   GoodFeatures (SeedSearcher::BestFeatures* next, bool owner,
                  const SeqCluster& db,
                  const SeqWeightFunction& wf,
                  double minScore, 
                  int minPos,
                  int minPosPercent);

   //
   // takes ownership of Assignment & Cluster
   virtual bool add (Feature_var feature);

   //
   // returns the minimum positive sequences that should contain a feature
   // if it is to be considered 'good'
   int minPositiveSequences () const {
      return _minPositiveSeqs;
   }



private:
   double _minScore;
   int _minPositiveSeqs;
   const SeqWeightFunction& _wf;
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












