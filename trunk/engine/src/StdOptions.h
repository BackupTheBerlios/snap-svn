#ifndef _SeedSearcher_StdOption_h
#define _SeedSearcher_StdOption_h

//
// File        : $RCSfile: $
//               $Workfile: StdOptions.h $
// Version     : $Revision: 38 $
//               $Author: Aviad $
//               $Date: 10/05/05 12:12 $
// Description :
//    Concrete implmentations for Langauge, Scores::Function, WeightFunction etc
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

#include "core/AutoPtr.h"

#include "persistance/Defs.h"
#include "persistance/TextWriter.h"

#include <boost/cast.hpp>

//
// this header contains the standard definitions used for SeedSearcher
//
/*
class ExpScore : public Scores::Function {
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
*/


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
   // (for instance the reverse assignment for ACGT langauge)
   virtual void complement (const Assignment&, Assignment&) const;
   virtual void complement (const Str&, StrBuffer&) const;

   //
   // return a wildcard with the appropriate strategy (for searching)
   virtual Assignment::Position wildcard (Assignment::Strategy s) const {
		switch (s) {
			default:
				mustfail ();

			case assg_discrete:
				//
				// there is no point in trying to specialize into the N character
				// because an N in the sequence means that the actual character is still
				// unknown
				return Assignment::Position (Assignment::Position::all, 4, s);
				break;

			case assg_together:
				//
				// a wildcard can match an N in the sequence
				return Assignment::Position (Assignment::Position::all, 5, s);
				break;
		}
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
	virtual void finalizeProjection (int numSeedsSearched) {
		_next->finalizeProjection (numSeedsSearched);
	}
	virtual void finalizeSetting (int numSeedsSearched, int numProjections) {
		_next->finalizeSetting (numSeedsSearched, numProjections);
	}

protected:
	boost::shared_ptr <SeedSearcher::FeatureFilter> _next;
};


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



class ScoreFeaturesFilter : public FeatureFilterLink {
   //
   // this class is intended to allow only features that
   // are good enough - have a score high enough
public:
	ScoreFeaturesFilter (boost::shared_ptr <SeedSearcher::FeatureFilter>& next	,
		                  double minLog2Score												)
	:  FeatureFilterLink (next), _minLog2Score (minLog2Score)
	{
	}

	ScoreFeaturesFilter (const ScoreFeaturesFilter& in)
		:  FeatureFilterLink (in),
		_minLog2Score (in._minLog2Score)
	{
	}
	//
	// takes ownership of Assignment & Cluster
	virtual bool add (Feature_var feature) {
		//
		// the corrected score should be used to find
		// good scoring features
		if (feature->log2score () > _minLog2Score)
			return false;

		return _next->add (feature);
	}

	virtual FeatureFilter* clone () {
		return new ScoreFeaturesFilter (*this);
	}

private:
	double _minLog2Score;
};

class FertileFeaturesFilter : public FeatureFilterLink {
	//
	// this class is intended to allow only features that
	// are good enough - (1) are present in at least k positive sequences
	//                   (2) are present in at least n percent of positive sequences
public:
	FertileFeaturesFilter (boost::shared_ptr <SeedSearcher::FeatureFilter>& next,
                  const SeqCluster& db,
                  const SeqWeightFunction& wf,
                  int minPos,
                  int minPosPercent);

   FertileFeaturesFilter (const FertileFeaturesFilter& in)
      :  FeatureFilterLink (in),
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
      return new FertileFeaturesFilter (*this);
   }

private:
   int _minPositiveSeqs;
   const SeqWeightFunction& _wf;
};

class FeaturePrintFilter : public FeatureFilterLink {
   //
   // this class is intended to print to file all seen features
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


class FDRCorrectionFilter : public FeatureFilterLink {
   //
   // this class is intended to print to file all seen features
public:
	FDRCorrectionFilter (boost::shared_ptr <SeedSearcher::FeatureFilter>& next)
		: FeatureFilterLink (next)
	{
	}

	virtual FeatureFilter* clone () {
		mustfail ();
		return NULL;
	}

	virtual void finalizeSetting (int numSeedsSearched, int numProjections);
};

class BonfCorrectionFilter : public FeatureFilterLink {
   //
   // this class is intended to print to file all seen features
public:
	BonfCorrectionFilter (	boost::shared_ptr <SeedSearcher::FeatureFilter>& next)
		: FeatureFilterLink (next)
	{
	}
	virtual FeatureFilter* clone () {
		mustfail ();
		return NULL;
	}

	virtual void finalizeSetting (int numSeedsSearched, int numProjections);
};


struct StatFix {
   //
   // given a list of features with decreasing scores (best ones first)
   // and a significant cut-off P (all bigger than P are significant)
   // returns the largest index K (1 based), whose value is still bigger than P*K/N.
   //
   // if no feature fits, returns 0
   // TODO: is this correct?
   static int FDR (SeedSearcher::FeatureFilter&, int N, double P);

   //
   // given a list of features with decreasing scores (best ones first)
   // and a significant cut-off P (all bigger than P are significant)
   // returns the largest index K (1 based), whose value is still bigger than P/N.
   //
   // if no feature fits, returns 0
   // TODO: is this correct?
   static int bonferroni (SeedSearcher::FeatureFilter&, int N, double P);
};

#endif // _SeedSearcher_StdOption_h












