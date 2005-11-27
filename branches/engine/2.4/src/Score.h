#ifndef _SeedSearcher_Score_h
#define _SeedSearcher_Score_h

#include "Defs.h"
#include "SeqWeight.h"

#include "persistance/TextWriter.h"

#include "legacy/MathPlus.h"
#include <boost/concept_check.hpp>
#include <boost/shared_ptr.hpp>

//Scores 
namespace Scores {

	struct TFPN {
		TFPN (int TP, int TN, int FP, int FN) : _TP (TP), _TN (TN), _FP (FP), _FN (FN) {
		}
		TFPN (const TFPN& tfpn) {
			*this = tfpn;
		}
		inline bool operator == (const TFPN& tfpn) const {
			return (_TP == tfpn._TP) && (_TN == tfpn._TN) && (_FP == tfpn._FP) && (_FP == tfpn._FP);
		}
		inline bool operator != (const TFPN& tfpn) const {
			return !(*this == tfpn);
		}
		bool operator < (const TFPN& tfpn) const{
			if (_TP != tfpn._TP) return _TP < tfpn._TP;
			else if (_TN != tfpn._TN) return _TN < tfpn._TN;
			else if (_FP != tfpn._FP) return _FP < tfpn._FP;
			else if (_FN != tfpn._FN) return _FN < tfpn._FN;
			else return false;
		}

		int _TP, _TN, _FP, _FN;
	};

	//
	// interface for scores
	//
	// IMPORTANT:
	// the smaller (more negative) the score, the better.
	// score MUST be in log2 format.
	class Score {
	public:
		virtual ~Score () {}
		inline double log10Score () const {
			static const double LOG10_2 = log10 (static_cast <double> (2));
			return _log2Score * LOG10_2; 
		}
		inline double log2Score () const {
			return _log2Score;
		}

		//
		// Score may be a composite
		virtual boost::shared_ptr <Score> next () const{
			return boost::shared_ptr <Score> ();
		}

		//
		// compare to another score
		int compare (const Score&) const;
		//virtual bool equals (const Score&) = 0;
		//virtual int hash () const = 0;

		virtual void name (StrBuffer&) const = 0;
		virtual TFPN& parameters(TFPN&) = 0;
		virtual void writeAsText (Persistance::TextWriter&) const = 0;

	//	virtual bool isEqual (const Score&);

	protected:
		double _log2Score;
	};
	typedef boost::shared_ptr <Score> Score_ptr;


	//
	// interface for score creation
	struct Factory {
		virtual ~Factory () {}
		virtual Score_ptr create (const TFPN&) const = 0;
	};



	//
	// this class represents a scoring scheme for features
	class Function {
	public:
		virtual ~Function () {
		}

		//
		// if 'parameters' is NULL, do not return ScoreParameters.
		virtual Score_ptr score (
			const Assignment& feature,
			const Assignment& projection,
			const SeqCluster& containingFeature) const = 0;
	};
	typedef boost::shared_ptr <Function> Function_ptr;

	//
	// utility for creating a score function
	boost::shared_ptr <Scores::Function> makeFunction (
		CountType countType,
		PositionWeightType scorePartial,
		boost::shared_ptr <SequenceDB>& db,
		boost::shared_ptr <SeqWeightFunction>& wf,
		boost::shared_ptr <Factory>& factory,
		int seedLength);



	//
	// 
	class HyperGeometricPvalue : public Score {
		//
		// x - how many of taken are red
		// k - how many balls taken
		// N - how many balls are red
		// M - how many total balls
	public:
		HyperGeometricPvalue (const TFPN&);

		virtual TFPN& parameters(TFPN& tfpn) {
			tfpn = _tfpn; return tfpn;
		}
		static void convert (const TFPN& tfpn, int& x, int& k, int& N,int& M);

		virtual void writeAsText (Persistance::TextWriter& writer) const {
			int x, k, N, M;
			convert (_tfpn, x, k, N, M);
			// [X=5, K=45, N=5, M=46]
			writer << "[X=" << x << ", K=" << k << ", N=" << N << ", M=" << M << ']';
		}
		virtual void name (StrBuffer& out) const { out = "HyperGeometric Pvalue"; }

	private:
		TFPN _tfpn;
	};


	//
	//
	struct HyperGeometricPvalueFactory : public Factory {
		HyperGeometricPvalueFactory ();
		~HyperGeometricPvalueFactory ();
		virtual boost::shared_ptr <Score> create (const TFPN&) const;

		struct Cache;
	};



	//
	//
	class ExplossWeights {
	public:
		ExplossWeights (double log2hitPos, double log2hitNeg) 
			: _log2HitPositiveWeight (log2hitPos), _log2HitNegativeWeight (log2hitNeg) 
		{
		}
		double log2HitPositiveWeight () const { return _log2HitPositiveWeight; }
		double log2HitNegativeWeight () const { return _log2HitNegativeWeight; }

	private:
		double _log2HitPositiveWeight;
		double _log2HitNegativeWeight;
	};


	
	//
	//
	class ExplossScore : public Score {
	public:
		ExplossScore (	const boost::shared_ptr <ExplossWeights>& weights,
							const TFPN& tfpn)
			: _tfpn (tfpn), _weights (weights)
		{
			//
			// the score is better (= smaller) whenever we find a weights match (= TP).
			// the score is worse (= larger) whenever we find a negative set match (= FP).
			// the score is unchanged by non-matching negative sequences (= TN).
			// the score is unchanged by non-matching positive sequences (= FN).
			_log2Score =	(_tfpn._FP * _weights->log2HitNegativeWeight ()) -
								(_tfpn._TP * _weights->log2HitPositiveWeight ());
		}
		virtual TFPN& parameters(TFPN& tfpn) {
			tfpn = _tfpn; return tfpn;
		}
		virtual void writeAsText (Persistance::TextWriter& writer) const {
			writer << "[FP = " << _tfpn._FP << ", TP=" << _tfpn._TP << ']';
		}
		virtual void name (StrBuffer& out) const { out = "Exploss Score"; }

	private:
		TFPN _tfpn;
		boost::shared_ptr <ExplossWeights> _weights;
	};


	//
	//
	class ExplossScoreFactory : public Factory {
	public:
		ExplossScoreFactory (const boost::shared_ptr <ExplossWeights>& weights)
			: _weights (weights)
		{
		}
		virtual boost::shared_ptr <Score> create (const TFPN& tfpn ) const;

		struct Cache;
	private:
		boost::shared_ptr <ExplossWeights> _weights;
	};


	//
	//
	class BonfCorrectedPvalue : public Score {
		//
		// Well-known Bonferroni correction:
		// Corrected-Pvalue = Pvalue / #trials
		//
		// See: http://mathworld.wolfram.com/BonferroniCorrection.html
	public:
		BonfCorrectedPvalue (boost::shared_ptr <Score> score, int repeatedTrials);

		virtual TFPN& parameters(TFPN& tfpn) {
			return _pscore->parameters(tfpn);
		}
		virtual void writeAsText (Persistance::TextWriter& writer) const {
			_pscore->writeAsText (writer);
			writer << "[Bonf N=" << _repeatedTrials << ']';
		}
		virtual void name (StrBuffer& out) const { out = "Bonferroni Corrected Pvalue"; }
		virtual boost::shared_ptr <Score> next () const { 
			return _pscore;
		}

	protected:
		boost::shared_ptr <Score> _pscore;
		int _repeatedTrials;
	};



	//
	//
	class FDRCorrectedPValue : public Score {
		//
		// FDR = False discovery rate. 
		// Using the Linear step-up procedure (Benjamini & Hochberg, 1995)
		//
		// Corrected-Pvalue = Pvalue * (N /k)
		// where N = #trials, and k is such that
		// The Pvalue is the k-th best score found in the trials
	public:
		FDRCorrectedPValue (	Score_ptr uncorrectedPvalue, 
									int repeatedTrials,
									int k,
									const FDRCorrectedPValue* previousScore
									);

		virtual TFPN& parameters(TFPN& tfpn) {
			return _pscore->parameters(tfpn);
		}
		virtual void writeAsText (Persistance::TextWriter& writer) const {
			_pscore->writeAsText (writer);
			writer	<< "[FDR N=" << _repeatedTrials 
						<< " k=" << _k 
						<< ']';
		}
		virtual void name (StrBuffer& out) const { out = "FDR Corrected Pvalue"; }
		virtual boost::shared_ptr <Score> next () const { 
			return _pscore;
		}

	protected:
		boost::shared_ptr <Score> _pscore;
		int _repeatedTrials;
		int _k;
	};
};

#endif
