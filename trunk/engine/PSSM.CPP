#include "PSSM.h"

//#include <MainLib.h>
//#include <Multinomial.h>
#include <vector>
#include <math.h>
#include <assert.h>

//int Multinomial::MaxN = 4;

// void
// Multinomial::setMaxN(int n) {
//   assert(n>0);
//   MaxN = n;
// }

Multinomial::Multinomial()
{
  _n = 0;
}

Multinomial::Multinomial(int n)
{
  _n = n;
  for( int i = 0; i < n; i++ )
    _PR[i] = 0;
}

Multinomial::Multinomial(const Multinomial& P )
{
  _n = P._n;
  for( int i = 0; i < _n; i++ )
    _PR[i] = P._PR[i];

}
/*
Multinomial::Multinomial(const vector<double>& P,const bool isExp )
{
  _n = P.size();
  for( int i = 0; i < _n; i++ )
    _PR[i] = P[i];
  isExp ? NormalizeExp() : Normalize();
}
*/

Multinomial
Multinomial::operator=(const Multinomial& P )
{
  _n = P._n;
  for( int i = 0; i < _n; i++ )
    _PR[i] = P._PR[i];
  return *this;
}


void
Multinomial::Normalize( )
{
  int i;
  double T = 0;
  for(  i = 0; i < _n; i++ )
    T +=_PR[i];
  
  if( T < 0.00001 )
    for(  i = 0; i < _n; i++ )
      _PR[i] = 1.0/_n;
  else
    for(  i = 0; i < _n; i++ )
      _PR[i] /= T;
}

void
Multinomial::NormalizeExp( )
{
  int i;

  double M = _PR[0];
  for(  i = 1; i < _n; i++ )
    if( _PR[i] > M )
      M = _PR[i];

  double T = 0;
  
  for(  i = 0; i < _n; i++ )
  {
    _PR[i] = exp( _PR[i] - M );
    T +=_PR[i];
  }
  
  if( T < 0.00001 )
    for(  i = 0; i < _n; i++ )
      _PR[i] = 1.0/_n;
  else
    for(  i = 0; i < _n; i++ )
      _PR[i] /= T;
}


void Multinomial::NormalizeCompExp()
{
  NormalizeExp();
  for (int  i = 0 ; i < _n; i++ )
    _PR[i] = 1 - _PR[i];
  Normalize();
}

/**
 * its the user reponsibility to use it on normallized dist only.
 * also note the user should avoid using it with prob of 0 in one of the values.
 * the multinomials themselves should be of the same size. 
 */

double
Multinomial::KL(Multinomial const & m ) const {
  assert (m._n == _n);
  double val = 0;
  for( int i = 0; i < _n; i++ )
  {
    val += (_PR[i]* (log(_PR[i])-log(m._PR[i])));

  }
  return val;
}

/*
ostream& operator<<(ostream& o, Multinomial const& P)
{
  o << "M[ ";
  for( int i =0 ; i < P._n; i++ )
  {
    if( i > 0 )
      o << " ";
    o << P._PR[i];
  }
  o << " ]";
  return o;
}

void
Multinomial::Read(istream& in )
{
  string s;
  in>>s;
  assert(!s.compare("M["));
  for( int i = 0 ; i < _n; i++ )
  {
    in>>_PR[i];
  }
  in>>s;
  assert(!s.compare("]"));
#if 0
  char *t;
  t = NextToken(in);
  assert( !strcmp(t, "M[" ) );
  for( int i = 0 ; i < _n; i++ )
  {
    char *t = NextToken(in);
    _PR[i] = atof(t);
    //    cerr << t << " -> " << _PR[i] << "\n";
  }
  
  t = NextToken(in);
  assert( !strcmp(t, "]" ) );

}
*/

int
Multinomial::MAP() const
{
  int M = 0;
  for( int i = 1 ; i < _n; i++ )
    if( _PR[i] > _PR[M] )
      M = i;

  return M;
}
