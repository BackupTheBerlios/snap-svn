#ifndef _SeedSearcher_StdOption_h
#define _SeedSearcher_StdOption_h

//
// File        : $RCSfile: $ 
//               $Workfile: StdOptions.h $
// Version     : $Revision: 34 $ 
//               $Author: Aviad $
//               $Date: 1/03/05 22:24 $ 
// Description :
//    Concrete implmentations for Langauge, ScoreFunction, WeightFunction etc
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

#include "Defs.h"
#include "SequenceDB.h"
#include "SeedSearcher.h"
#include "AssignmentFormat.h"

#include "HyperGeoCache.h"
#include "core/AutoPtr.h"

#include "persistance/Defs.h"
#include "persistance/TextWriter.h"

#include <boost/cast.hpp>

//
// this header contains the standard definitions used for SeedSearcher
//

class ExpScore : public ScoreFunction {
public:
   virtual ~ExpScore () {
   }    
   ExpScore(double alpha, double beta, const SeqWeightFunction& wf) 
      :  _log2alpha(log2(alpha)),
         _log2beta(log2(beta)),
         _wf(wf) 
   {
   }

    struct ExpParameters : public ScoreParameters {
       ExpParameters (int pos, int neg) 
          : _pos (pos), _neg (neg) {
       }
       virtual ~ExpParameters () {
       }

       int _pos, _neg;
    };


   //
   // if 'parameters' is NULL, do not return ScoreParameters.
    virtual double log2score (  const Assignment& feature,
                           const Assignment& projection,
                           const SeqCluster& containingFeature, // k
                           ScoreParameters** parameters
                           ) const 
   {
       SeqCluster::CountSequences pos_cs,neg_cs;
       containingFeature.performDivided(_wf,pos_cs,neg_cs);

       *parameters = new ExpParameters (pos_cs.result(), neg_cs.result());
       return (neg_cs.result()*_log2beta - pos_cs.result()*_log2alpha);
   }

   //
   // print the score parameters 
   virtual void writeAsText ( Persistance::TextWriter& writer, 
                              const ScoreParameters* params) const 
   {
      const ExpParameters* p = boost::polymorphic_downcast<const ExpParameters*> (params);
      writer << "beta^" << p->_neg << "/alpha^" << p->_pos;
   }

private:
    double _log2alpha, _log2beta;
    const SeqWeightFunction & _wf;   
};


class ACGTLangauge : public Langauge{
   //
   // this class defines the ACGT langauge
public:
   enum {
      ACode = 0x1,
      CCode = 0x2,
      GCode = 0x4,
      TCode = 0x8,
      NCode = 0x10, // for N in the seq file
   };
   ACGTLangauge (bool useReverse = true, bool includeN = false) 
   : _includeN (includeN), _useReverse (useReverse) 
   {
   }
   virtual ~ACGTLangauge () {
   }

   //
   // convert assignment position to text,
   // used to display search results
   virtual void write (const Assignment::Position&, Persistance::TextWriter& out) const ;

   //
   // returns the complement of an assignment 
   // (for instance the reverse assignment for ACGT langugaue)
   virtual void complement (const Assignment&, Assignment&) const;
   virtual void complement (const Str&, StrBuffer&) const;

   //
   // return a wildcard with the appropriate strategy (for searching)
   virtual Assignment::Position wildcard (Assignment::Strategy s) const {
      //
      // currently wildcards do not match 'N' characters.
      // this may seem ridiculous because these are supposed to be wildcards
      // after all, but really 'N' means I-dunno-whats-there
      // so if you want to match dunno's you'd better ask for it
      return Assignment::Position (Assignment::Position::all, 4, s);
   }

   //
   // return the code of the langauge
   virtual const AlphabetCode& code () const {
      return getCode (_includeN);
   }
   virtual bool supportComplement () const {
      return _useReverse;
   }
   void supportComplement (bool in) {
      _useReverse = in;
   }

   //
   // get the cardinality of the alphabet 
   // (depends on inclusion of 'N' in alphabet)
   virtual int cardinality () const{
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

   virtual Assignment& stringToAssignment (Assignment& motif, const Str& motif_str) const {
      int l = motif_str.length ();
      for (int i=0 ; i<l ; i++) {
         AlphabetCode::Char c = motif_str.getCharAt (i);
         if (c == '?' || c == 'N') {
            motif.addPosition (wildcard (assg_together));
         }
         else if (c == '*') {
            motif.addPosition (wildcard (assg_discrete));
         }
         else {
            AlphabetCode::CodedChar cc = code ().code (c);
            if (cc == AlphabetCode::notInCode) {
               throw AlphabetCode::UnknownCodeError (c);
            }

            //
            // create a position for each char in the string, 
            // using assg_discrete strategy
            motif.addPosition (AssgPosition (cc, assg_discrete));
         }
      }

      return motif;
   }

protected:
   //
   // if true includes the char 'N' in the langauge
   bool _includeN;
   bool _useReverse;
};


//
//
class SimpleWeightFunction : public SeqWeightFunction {
public:
   SimpleWeightFunction (boost::shared_ptr <SeqWeightDB::ID2Weight> weights,
                        double inThreshold) 
   : SeqWeightFunction (weights), _threshold (inThreshold) {
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

/*
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
*/

//
//
class FeatureFilterLink : public SeedSearcher::FeatureFilter {
   //
   // this class is the base class of all FeatureFilter classes
   // that do only partial processing of a feature, before passing
   // the feature along to the next FeatureFilter link
public:
	FeatureFilterLink (boost::shared_ptr <SeedSearcher::FeatureFilter>& next) 
   : _next (next) {
   }
   FeatureFilterLink (const FeatureFilterLink& in)
   : _next (in._next->clone ())
   {
   }

   virtual ~FeatureFilterLink () {
   }
   virtual bool add (Feature_var feature) {
      return _next->add (feature);
   }

   virtual const FeatureSet_ptr getArray () const {
      return _next->getArray ();
   }
   virtual FeatureSet_ptr getArray () {
      return _next->getArray ();
   }
	virtual void finalize () {
		_next->finalize ();
	}

protected:
	boost::shared_ptr <SeedSearcher::FeatureFilter> _next;
};

/*
class BookkeeperFilter : public FeatureFilterLink {
   //
   // this class maintains information about the candidate features
public:
   BookkeeperFilter (SeedSearcher::FeatureFilter* next, bool owner) 
      :  FeatureFilterLink (next, owner), 
         _dirty (false), 
         _log2Sum (-HUGE_VAL), 
         _log2InverseSum (-HUGE_VAL), 
         _noFeatures (0)
   {
   }

   //
   // takes ownership of Assignment & Cluster
   virtual bool add (Feature_var feature) {
     _noFeatures++;
     _log2Sum = AddLog2 (_log2Sum, feature->log2score ());
     _log2InverseSum = AddLog2 (_log2InverseSum, -feature->log2score ());

      return FeatureFilterLink::add (feature);
   }

   //
   // returns the number of candidates seen
   int noFeaturesSeen () const {
      return _noFeatures;
   }

   //
   // we return the sum over each candidate i:
   // log2 (sum (2^score(i)))
   double log2SumScoresSeen () const {
      return _log2Sum;
   }

   double log2InverseSumScoresSeen () const {
      return _log2InverseSum;
   }

   //
   // for each 'best' feature i we perform
   // log2(score (i)) = log2(score(i)) - log2SumScoresSeen ()
   //                 = log2( score(i) / sumScoresSeen () )
   void normalizeBackgroundScoresLinear () {
      SeedSearcher::FeatureArray& arr = getArray ();
      for (int i=0 ; i < arr.size () ; i++) {
         arr[i].log2score (-arr[i].log2score () - log2InverseSumScoresSeen ());
      }
   }

protected:
   bool _dirty;
   double _log2Sum;
   double _log2InverseSum;
   int _noFeatures;
};
*/
#include "FeatureSet.h"

class KBestFilter : public SeedSearcher::FeatureFilter {
   //
   // this class is intended to maintain a buffer of the K-best
   // features found.
public:
   //KBestFilter (int k, int maxRedundancyOffset);
	KBestFilter (int k, int maxRedundancyOffset, FeatureSet_ptr = FeatureSet_ptr ());
   KBestFilter (const KBestFilter& in) 
   :  _maxElements (in._maxElements),
      _maxRedundancyOffset (in._maxRedundancyOffset),
		_features (new FeatureSet)
   {
		//
		// we do not copy the featureset contents
   }
   virtual ~KBestFilter ();

   //
   // takes ownership of Assignment & Cluster
   virtual bool add (Feature_var feature) {
      return _features->insertOrReplace1 (
         feature, 
         FeatureSet::featureRedundancyCheck (
            FeatureSet::SymmetricMaxOffsetRedundancyCheck (
               _maxRedundancyOffset
            )
         ),
         _maxElements 
      );
   }

   virtual FeatureSet_ptr getArray () {
      return _features;
   }
   virtual const FeatureSet_ptr getArray () const {
      return _features;
   }
   virtual FeatureFilter* clone () {
      return new KBestFilter (*this);
   }

	virtual void finalize () {
	}

protected:
   int _maxElements;
   int _maxRedundancyOffset;
	boost::shared_ptr <FeatureSet> _features;
};


//
//
class KBestComplementFilter : public KBestFilter {
public:
   KBestComplementFilter (	int k, int maxRedundancyOffset, 
									const Langauge& langauge,
									FeatureSet_ptr features = FeatureSet_ptr ())
   :  KBestFilter (k, maxRedundancyOffset, features), _langauge (langauge)
   {
   }
   KBestComplementFilter (const KBestComplementFilter& in)
   :  KBestFilter (in), _langauge (in._langauge)
   {
   }
   virtual ~KBestComplementFilter () {
   }

   virtual bool add (Feature_var feature) {
      return _features->insertOrReplace1 (
         feature, 
         FeatureSet::featureReverseRedundancyCheck (
            FeatureSet::SymmetricMaxOffsetRedundancyCheck (
               _maxRedundancyOffset
            ),
            _langauge
         ),
         _maxElements 
      );
   }

   virtual FeatureFilter* clone () {
      return new KBestComplementFilter (*this);
   }

protected:
   const Langauge& _langauge; 
};



class GoodFeaturesFilter : public FeatureFilterLink {
   //
   // this class is intended to allow only features that
   // are good enough - (1) have a score high enough
   //                   (2) are present in at least k positive sequences
   //                   (3) are presnt in at least n percent of positive sequences
public:
	GoodFeaturesFilter (boost::shared_ptr <SeedSearcher::FeatureFilter>& next,
                  const SeqCluster& db,
                  const SeqWeightFunction& wf,
                  double minScore, 
                  int minPos,
                  int minPosPercent);

   GoodFeaturesFilter (const GoodFeaturesFilter& in)
      :  FeatureFilterLink (in),
         _minScore (in._minScore), 
         _minPositiveSeqs (in._minPositiveSeqs),
         _wf (in._wf)
   {
   }
   //
   // takes ownership of Assignment & Cluster
   virtual bool add (Feature_var feature);

   //
   // returns the minimum positive sequences that should contain a feature
   // if it is to be considered 'good'
   int minPositiveSequences () const {
      return _minPositiveSeqs;
   }

   virtual FeatureFilter* clone () {
      return new GoodFeaturesFilter (*this);
   }

private:
   double _minScore;
   int _minPositiveSeqs;
   const SeqWeightFunction& _wf;
};

class FeaturePrintFilter : public FeatureFilterLink {
   //
   // this class is intended to allow only features that
   // are good enough - (1) have a score high enough
   //                   (2) are present in at least k positive sequences
   //                   (3) are presnt in at least n percent of positive sequences
public:
	FeaturePrintFilter (	boost::shared_ptr <SeedSearcher::FeatureFilter>& next,
								const Str& name);

   //
   // takes ownership of Assignment & Cluster
   virtual bool add (Feature_var feature);

	virtual FeatureFilter* clone () {
		mustfail ();
		return NULL;
	}

	virtual void finalize () {
		_writer.flush ();
	}

protected:
	Persistance::TextWriter _writer;
};


struct StatFix {
   //
   // given a list of features with decreasing scores (best ones first)
   // and a significant cut-off P (all bigger than P are siginificant)
   // returns the largest index K (1 based), whose value is still bigger than P*K/N.
   //
   // if no feature fits, returns 0
   // TODO: is this correct?
   static int FDR (SeedSearcher::FeatureFilter&, int N, double P);

   //
   // given a list of features with decreasing scores (best ones first)
   // and a significant cut-off P (all bigger than P are siginificant)
   // returns the largest index K (1 based), whose value is still bigger than P/N.
   //
   // if no feature fits, returns 0
   // TODO: is this correct?
   static int bonferroni (SeedSearcher::FeatureFilter&, int N, double P);
};

#endif // _SeedSearcher_StdOption_h












