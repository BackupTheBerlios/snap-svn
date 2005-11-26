#ifndef __MathFunctions_h
#define __MathFunctions_h

#include <math.h>
#include <assert.h>
#include "MathPlus.h"

inline double exp2(double x) 
{ 
  return exp(x*log(2.0));
}

#ifndef log2
inline double log2(double x) 
{
  return log(x)/log(2.0);
}
#endif

///
inline double lChoose( double k , double n )
{
  if( k > 0 && k < n )
    return (lgamma( n + 1 ) - lgamma( k + 1 ) - lgamma( n - k + 1 ))/log(2.0);
  else
    return 0;
}

///
inline double l2gamma(double x )
{
  return lgamma(x) / log(2.0);
}

///
inline double digamma(double x)
{
  return ( log(x) - 1/(2*x) - 1/(12*pow(x,2)) +
	   1/(120*pow(x,4)) - 1/(252*pow(x,6)));
}

///
inline double digamma1(double x)
{
  return (1/x + 1/(2*pow(x,2) + 1/(6*pow(x,3)) -
	   1/(30*pow(x,5)) + 1/(42*pow(x,7)) ));
}

///
inline double
GaussPDF(double x, double mu, double sigma2 )
{
  double z = (x -mu)/sqrt(sigma2);
  return 0.5*( 1 + erf(z / M_SQRT2 ));
}

///
inline double
Gausspdf(double x, double mu, double sigma2 )
{
  double z = (x -mu);
  return 1/sqrt(2*M_PI*sigma2)*exp(-0.5*z*z/sigma2);
}

///
/*
inline double
AddLog(double x, double y )
{
  if( x == -HUGE_VAL ) return y;
  if( y == -HUGE_VAL ) return x;
  
  double z = max(x,y);
  return z + log(exp(x-z) + exp(y-z));
}
*/

///
inline double
AddLog2(double x, double y )
{
  if( x == -HUGE_VAL ) return y;
  if( y == -HUGE_VAL ) return x;

  double z;
  if( x > y )
    z = y - x;
  else
  {
    z = x - y;
    x = y;
  }
  return x + log2(1 + exp2(z));
}

///
inline double
SubLog2(double x, double y )
{
  assert( x >= y );
  return x + log2(1 - exp2(y-x));
}

#define EPS 0.000000001
#define UNDEF_VAL    -1000000000
#define UNDEF_PROB   1.0

#endif

// 	$Header: /CS/course/1999/cbio/CVS/LibB/Include/MathFunctions.h,v 1.4 2000/10/28 20:06:55 nirf Exp $	










