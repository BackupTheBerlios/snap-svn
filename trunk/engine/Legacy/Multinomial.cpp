#include "Multinomial.h"

#include "ExtraMath.h"

#include <vector>
#include <assert.h>




//int tMultinomial::MaxN = 4;

// void
// tMultinomial::setMaxN(int n) {
//   assert(n>0);
//   MaxN = n;
// }

tMultinomial::tMultinomial()
{
  _n = 0;
}

tMultinomial::tMultinomial(int n)
{
  _n = n;
  for( int i = 0; i < n; i++ )
    _PR[i] = 0;
}

tMultinomial::tMultinomial(const tMultinomial& P )
{
  _n = P._n;
  for( int i = 0; i < _n; i++ )
    _PR[i] = P._PR[i];

}

tMultinomial::tMultinomial(const std::vector<double>& P,const bool isExp )
{
  _n = P.size();
  for( int i = 0; i < _n; i++ )
    _PR[i] = P[i];
  isExp ? NormalizeExp() : Normalize();
}

tMultinomial
tMultinomial::operator=(const tMultinomial& P )
{
  _n = P._n;
  for( int i = 0; i < _n; i++ )
    _PR[i] = P._PR[i];
  return *this;
}


void
tMultinomial::Normalize( )
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
tMultinomial::NormalizeExp( )
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


void tMultinomial::NormalizeCompExp()
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
tMultinomial::KL(tMultinomial const & m ) const {
  assert (m._n == _n);
  double val = 0;
  for( int i = 0; i < _n; i++ )
  {
    val += (_PR[i]* (log(_PR[i])-log(m._PR[i])));

  }
  return val;
}


std::ostream& operator<<(std::ostream& o, tMultinomial const& P)
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
tMultinomial::Read(std::istream& in )
{
  std::string s;
  in>>s;
  assert(!s.compare("M["));
  for( int i = 0 ; i < _n; i++ )
  {
    in>>_PR[i];
  }
  in>>s;
  assert(!s.compare("]"));
  /*
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
  */
}

int
tMultinomial::MAP() const
{
  int M = 0;
  for( int i = 1 ; i < _n; i++ )
    if( _PR[i] > _PR[M] )
      M = i;

  return M;
}








