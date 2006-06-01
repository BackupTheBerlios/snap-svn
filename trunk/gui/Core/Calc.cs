using System;
using System.Collections.Generic;
using System.Text;

namespace SNAP {
    public class HyperGeometric {
      private const int MAX_GAMMA = 8000;
      private static double [] lgammaVal = new double [MAX_GAMMA];
      private static double [] first4 = new double [] {0,0,0,0};
      private static double [] first4Val = new double [4];
      private static int index = 0;
      private static bool init = false;

    public static double lgamma(double x) {
        return (System.Math.Log((((((.0112405826571654074 / ((x) + 5.00035898848319255) + .502197227033920907) / ((x) + 3.99999663000075089) + 2.09629553538949977) / ((x) + 3.00000004672652415) + 2.25023047535618168) / ((x) + 1.99999999962010231) + .851370813165034183) / ((x) + 1.00000000000065532) + .122425977326879918) / (x) + .0056360656189756065) + ((x) - .5) * System.Math.Log((x) + 6.09750757539068576) - (x));
    }

   //
   // copied from legacy SeedSearcher MyMath.h
   /**
   *param : log(X) , log(Y).
   *return: log(X+Y)
   * Note: by default if one of the given is 0 just returns the other ,as it assumes this is the start of cumulative
   * procedure summing prob.
   * if one wants to treat 0 as log(1) than ignoreZero should be set to false.
   */
   public static double addLog(double logX , double logY)
   {
       return addLog (logX, logY);
   }

   public static double addLog(double logX, double logY, bool ignoreZero)
   {
      if (ignoreZero) {
         if (logX == 0) return logY;
         if (logX == 0) return logX;
      }
      if (logX <= double.MinValue) return logY;
      if (logY <= double.MinValue) return logX;
      double m = (logX > logY) ? logX : logY;
      return (m + System.Math.Log(System.Math.Exp(logX - m) + System.Math.Exp(logY - m)));
   }

   static double gammaln(int n)  {
      // simple implementation (for naturals only)
      // log(gamma(n))=log((n-1)!)=log(1)+..+log(n-1)
      // verified against matlab's gammaln.m
      /*   static map<int,double> lgammaVal; */
      if (!init) {
         for (int i=0;i<MAX_GAMMA;i++)
            lgammaVal[i] = 0;

         init = true;
      }

      //try the x,k cache:
      System.Diagnostics.Debug.Assert (n>0);
      
      if ( n < MAX_GAMMA) {
         if(lgammaVal[n]==0) 
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

   public static double loghygepdf(int x, int m, int k, int n) {
      //taking the pdf def - substituting gamma for factorial,
      //and computing logs to raise exp to result at end
      // verified against matlab's hygepdf.m

      System.Diagnostics.Debug.Assert (0<=x && x<=n && n<=m && x<=k && k<=m && k-x<=m-n);
      // can be extended in x so that all other values receive 0

      double kx, mn, mknx; // we group folowing matlab, for no apparent reason

      kx   = gammaln(k+1)   - gammaln(x+1)   - gammaln(k-x+1);
      mn   = gammaln(m+1)   - gammaln(n+1)   - gammaln(m-n+1);
      mknx = gammaln(m-k+1) - gammaln(n-x+1) - gammaln(m-n-k+x+1);

      return (kx+mknx-mn);
   }

   public static double logTailhyge(int x, int m, int k, int n) {
      // we compute the straight forward pdf sum over the smaller
      // range between computing the cdf or its complementary
      // verified against matlab's hygecdf.m

       System.Diagnostics.Debug.Assert(0 <= x && x <= n && n <= m && x <= k && k <= m && k - x <= m - n);
      // can be extended: non int x => compute for floor(x)
      //                  x<0 => cdf = 0
      //                  x>min(k,n) => cdf = 1
      double sum = double.MinValue;
      int xmax = (k<n ? k : n); // can't get more hits than that

      for (int i=x; i<=xmax; i++)  // its complementary
         sum = addLog(sum,loghygepdf(i,m,k,n),false);

      return(sum);
   }

   public static void TFPN2Params (double TP, double FP, double TN, double FN,
                        out int x, out int k, out int N, out int M)
   {
       x = (int) System.Math.Round (TP);
       k = (int) System.Math.Round(TP + FP);
       N = (int) System.Math.Round(TP + FN);
       M = (int) System.Math.Round(TP + FP + TN + FN);
       System.Diagnostics.Debug.Assert (0 <= x);
       System.Diagnostics.Debug.Assert(x <= k);
       System.Diagnostics.Debug.Assert(x <= N);
       System.Diagnostics.Debug.Assert(N <= M);
       System.Diagnostics.Debug.Assert(k <= M);
       System.Diagnostics.Debug.Assert(k - x <= M - N);
   }
};
}
