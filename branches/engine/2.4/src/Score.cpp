#include "Score.h"
#include "ScoreFunction.h"

#include <assert.h>
#include "ExtraMath.h"

//
// class for computing hyper-geometric pvalues
class HyperGeometric {
   //
   // copied from legacy SeedSearcher MyMath.h
public:
   /**
   *param : log(X) , log(Y).
   *return: log(X+Y)
   * Note: by default if one of the given is 0 just returns the other ,as it assumes this is the start of cumulative
   * procedure summing prob.
   * if one wants to treat 0 as log(1) than ignoreZero should be set to false.
   */
   inline static 
      double addLog(double logX , double logY , bool ignoreZero = true)
   {
      if (ignoreZero) {
         if (! logX) return logY;
         if (! logY) return logX;
      }
      if (logX == -HUGE_VAL) return logY;
      if (logY == -HUGE_VAL) return logX;
      double m = (logX > logY) ? logX : logY;
      return (m+log(exp(logX-m)+exp(logY-m)) );
   }

   inline static
      double gammaln(int n)  {
      // simple implementation (for naturals only)
      // log(gamma(n))=log((n-1)!)=log(1)+..+log(n-1)
      // verified against matlab's gammaln.m
      /*   static map<int,double> lgammaVal; */
      static const int MAX_GAMMA = 8000;
      static double lgammaVal [MAX_GAMMA];
      static double first4[4] = {0,0,0,0};
      static double first4Val[4];
      static int index = 0;
      static bool init = false;

      if (!init) {
         for (int i=0;i<MAX_GAMMA;i++)
            lgammaVal[i] = 0;

         init = true;
      }

      //try the x,k cache:
      assert(n>0);
      
      if ( n < MAX_GAMMA) {
         if(! lgammaVal[n]) 
            lgammaVal[n] = lgamma(n);

         return lgammaVal[n];
      }

      // check the n,m cache:
      for (int i=0;i<4;i++) {
         if (first4[i] == n)
            return first4Val[i];
      }

      if (index < 4) {
         first4[index] = n;
         first4Val[index] = lgamma(n);
         index++;
         return first4Val[index-1];
      }
      
      return lgamma(n);// no cach helped here...

      /*   if (lgammaVal.find(n) == lgammaVal.end()) */
      /*     lgammaVal[n] = lgamma(n); */



      /*   double sum = 0.0; //log(1)=0 */
      /*   for (int i=2; i<=n-1; i++) */
      /*     sum += log(i); */

      /*   return(sum); */
   }

   inline static
      double loghygepdf(int x, int m, int k, int n)  {
      //taking the pdf def - substituting gamma for factorial,
      //and computing logs to raise exp to result at end
      // verified against matlab's hygepdf.m

      assert (0<=x && x<=n && n<=m && x<=k && k<=m && k-x<=m-n);
      // can be extended in x so that all other values receive 0

      double kx, mn, mknx; // we group folowing matlab, for no apparent reason

      kx   = gammaln(k+1)   - gammaln(x+1)   - gammaln(k-x+1);
      mn   = gammaln(m+1)   - gammaln(n+1)   - gammaln(m-n+1);
      mknx = gammaln(m-k+1) - gammaln(n-x+1) - gammaln(m-n-k+x+1);

      return (kx+mknx-mn);
   }

   inline static
      double logTailhyge(int x, int m, int k, int n) {
      // we compute the straight forward pdf sum over the smaller
      // range between computing the cdf or its complementary
      // verified against matlab's hygecdf.m

      assert (0<=x && x<=n && n<=m && x<=k && k<=m && k-x<=m-n);
      // can be extended: non int x => compute for floor(x)
      //                  x<0 => cdf = 0
      //                  x>min(k,n) => cdf = 1
      double sum = -HUGE_VAL;
      int xmax = (k<n ? k : n); // can't get more hits than that

      for (int i=x; i<=xmax; i++)  // its complementary
         sum = addLog(sum,loghygepdf(i,m,k,n),false);

      return(sum);
   }
};



using namespace Scores;


Scores::HyperGeometricPvalue::HyperGeometricPvalue (const TFPN& tfpn)
: _tfpn (tfpn)
{
	int x, k, N, M;
	convert (_tfpn, x, k, N, M);
	static const double LN_2 = ::log (static_cast <double> (2));
	_log2Score = HyperGeometric::logTailhyge(x, M, k, N) / LN_2;
}

void 
Scores::HyperGeometricPvalue::
convert (const TFPN& tfpn, int& x, int& k, int& N,int& M)
{
	x = tfpn._TP;
	k = tfpn._TP + tfpn._FP;
	N = tfpn._TP + tfpn._FN;
	M = tfpn._TP + tfpn._FP + tfpn._TN + tfpn._FN;
	debug_mustbe (0<=x);
	debug_mustbe (x<=k);
	debug_mustbe (x<=N);
	debug_mustbe (N<=M);
	debug_mustbe (k<=M);
	debug_mustbe (k-x<=M-N);
}


Scores::BonfCorrectedPvalue::
BonfCorrectedPvalue (boost::shared_ptr <Score> score, int repeatedTrials)
	: _pscore (score), _repeatedTrials (repeatedTrials)
{
	_log2Score = _pscore->log2Score() + log2 (_repeatedTrials);
}


Scores::FDRCorrectedPValue::
FDRCorrectedPValue (	boost::shared_ptr <Score> score, 
							int repeatedTrials,
							int k,
							const FDRCorrectedPValue* previousScore
							)
	: _pscore (score), _repeatedTrials (repeatedTrials)
{
	_log2Score = _pscore->log2Score() + log2 (_repeatedTrials) - log2 (_k);
	//
	// the k-th best Pvalue must be better than the (k+1)th Pvalue
	// even after the correction
	if (previousScore != NULL)
		_log2Score = tmin (_log2Score, previousScore->log2Score());
}


boost::shared_ptr <Scores::Function> 
Scores::makeFunction (
		CountType countType,
		PositionWeightType scorePartial,
		boost::shared_ptr <SequenceDB>& db,
		boost::shared_ptr <SeqWeightFunction>& wf,
		boost::shared_ptr <Factory>& factory,
		int seedLength
		)
{
	switch (scorePartial) {
		case _position_weight_discrete_:
			switch (countType) {
				case _count_gene_:
					return boost::shared_ptr <Scores::Function> (
						new DiscriminativeFunction <
							detail::PositionWeighter <_position_weight_discrete_>, 
							detail::PositionCounter <_count_gene_>
						> (db, wf, factory, seedLength)
					);
				case _count_total_:
					return Function_ptr (
						new DiscriminativeFunction <
							detail::PositionWeighter <_position_weight_discrete_>, 
							detail::PositionCounter <_count_total_>
						> (db, wf, factory, seedLength)
					);
			};
			break;

		case _position_weight_real_:
			switch (countType) {
				case _count_gene_:
					return Function_ptr (
						new DiscriminativeFunction <
							detail::PositionWeighter <_position_weight_real_>, 
							detail::PositionCounter <_count_gene_>
						> (db, wf, factory, seedLength)
					);

				case _count_total_:
					return Function_ptr (
						new DiscriminativeFunction <
							detail::PositionWeighter <_position_weight_real_>, 
							detail::PositionCounter <_count_total_>
						> (db, wf, factory, seedLength)
					);
			};
			break;

		case _position_weight_hotspots_:
			switch (countType) {
				case _count_gene_:
					return Function_ptr (
						new DiscriminativeFunction <
							detail::PositionWeighter <_position_weight_hotspots_>, 
							detail::PositionCounter <_count_gene_>
						> (db, wf, factory, seedLength)
					);

				case _count_total_:
					return Function_ptr (
						new DiscriminativeFunction <
							detail::PositionWeighter <_position_weight_hotspots_>, 
							detail::PositionCounter <_count_total_>
						> (db, wf, factory, seedLength)
					);
			};
			break;
	};

	mustfail ();
	return boost::shared_ptr <Scores::Function>  ();
}

//
// compare to another score
// returns -1 if MY score is better (lower)
// returns 1 if the OTHER score is better (lower)
// returns 0 if the scores are equal
int Scores::Score::compare (const Score& other) const
{
	double myscore = log2Score ();
	double oscore = other.log2Score ();
	Score* mynext = next ().get ();
	Score* onext = other.next ().get ();
	while ((myscore == oscore) && ((mynext != NULL) || (onext != NULL))) {
		if (mynext != NULL) {
			myscore = mynext->log2Score ();
			mynext = mynext->next ().get ();
		}
		if (onext != NULL) {
			oscore = onext->log2Score ();
			onext = onext->next ().get ();
		}
	}

	if (myscore < oscore) return -1;
	else if (myscore > oscore) return 1;
	else return 0;
}


//
// TODO: should this be implemented in hash table?
typedef std::map <Scores::TFPN, boost::shared_ptr <Scores::HyperGeometricPvalue> > HGScoreMap;

struct Scores::HyperGeometricPvalueFactory::Cache : public HGScoreMap {
} _hgcache;


Scores::HyperGeometricPvalueFactory::HyperGeometricPvalueFactory ()
{
}

Scores::HyperGeometricPvalueFactory::~HyperGeometricPvalueFactory ()
{
}

Scores::Score_ptr Scores::HyperGeometricPvalueFactory::create (const TFPN& tfpn) const
{
	TFPN converted (0, 0, 0, 0);
	HyperGeometricPvalue::convert (tfpn, converted._TP, converted._TN, converted._FP, converted._FN); 

	Cache::iterator it = _hgcache.lower_bound (tfpn);
	if (it == _hgcache.end () || it->first != tfpn) {
		it = _hgcache.insert (
			it,
			std::make_pair (
				converted, 
				boost::shared_ptr <HyperGeometricPvalue> (
					new HyperGeometricPvalue (tfpn)
				)
			)
		);
		debug_mustbe (it == _hgcache.find (converted));
		debug_only (tfpn == it->second->parameters (converted));
	}
	return it->second;
}


typedef std::map <Scores::TFPN, boost::shared_ptr <Scores::ExplossScore> > ExplossScoreMap;
struct Scores::ExplossScoreFactory::Cache : public ExplossScoreMap {
} _explosscache;

boost::shared_ptr <Score> Scores::ExplossScoreFactory::create (const TFPN& tfpn ) const 
{
	Cache::iterator it = _explosscache.lower_bound (tfpn);
	if (it == _explosscache.end () || it->first != tfpn) {
		it = _explosscache.insert (
			it,
			std::make_pair (
				tfpn, 
				boost::shared_ptr <ExplossScore> (
					new ExplossScore (_weights, tfpn)
				)
			)
		);
		debug_only (
			TFPN test (0, 0, 0, 0);
			debug_mustbe (it == _explosscache.find (tfpn));
			debug_mustbe (tfpn == (it->second->parameters (test)));
		);
	}
	return it->second;
}
