#ifndef _SeedSearcher_Math_h
#define _SeedSearcher_Math_h

#include <assert.h>
#include "ExtraMath.h"

#include "SeedSearcher.h"



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



class HyperGeoCache {
public:
   //
   // k - how many balls taken
   // x - how many of taken are red
   // n - how many balls are red
   // m - how many total balls
   HyperGeoCache (int n, int m);
   ~HyperGeoCache ();

   double logTail (int x, int k);
   double logTail (int x, int k, ScoreParameters**);

   void writeAsText (Persistance::TextWriter&, const ScoreParameters*) const;

   struct XK;
   class Score;

   struct Cache;
   Cache* _cache;
};


class HyperGeoTotalCache {
public:
   //
   // k - how many balls taken
   // x - how many of taken are red
   // n - how many balls are red
   // m - how many total balls
   HyperGeoTotalCache ();
   ~HyperGeoTotalCache ();

   double logTail (int x, int k, int n, int m);
   double logTail (int x, int k, int n, int m, ScoreParameters**);

   void writeAsText (Persistance::TextWriter&, const ScoreParameters*) const;

   struct XKNM;
   class Score;

   struct Cache;
   Cache* _cache;
};

#endif











