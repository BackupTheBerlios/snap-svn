#ifndef __Multinomial_h
#define __Multinomial_h

#include <iostream>
#include <vector>
#include <string>

class tDirichletPrior;

#define MaxN 40
class tMultinomial {
  //static const int MaxN = 40;
//  const int MaxN = 40;
public:
  //static void setMaxN(int n);
  
  tMultinomial();
  tMultinomial(int n);
  tMultinomial(const std::vector<double>&, const bool isExp);
  tMultinomial(const tMultinomial& );
  tMultinomial operator=( const tMultinomial& );
  bool operator==( const tMultinomial& ) const;
  bool operator!=( const tMultinomial& )const;
  
  double operator[]( int i ) const;
  double& operator[]( int i );

  int size() const;
  void Normalize();
  void NormalizeExp();
  /**
   * a simple method to compute the (complementary) normalized probbility ,
   * when each value is given in it's log form , and we normlize by the (1-prob) of each value.
   */
  void NormalizeCompExp();
  //void getParams(int & n , double const * & p) const;
  double const * getParams(int & n ) const;
  
  friend std::ostream& operator<<(std::ostream&, tMultinomial const&);

  void Read( std::istream& );

  int MAP() const;
  
  /**
   * its the user reponsibility to use it on normallized dist only.
   * also note the user should avoid using it with prob of 0 in one of the values.
   * the multinomials themselves should be of the same size. 
   */
  double KL(tMultinomial const & m) const ;
  
  friend class tDirichletPrior;
  
 private:
  int _n; 
  double _PR[MaxN];

};

inline
double
tMultinomial::operator[]( int i ) const
{
  return _PR[i];
}

inline
double&
tMultinomial::operator[]( int i ) 
{
  return _PR[i];
}

inline
bool tMultinomial::operator==(tMultinomial const & m) const {
  if(_n != m._n) return false;
  for (int i =0;i<_n;i++)
    if (_PR[i]!=m._PR[i]) return false;
  return true;
}

inline
bool tMultinomial::operator!=(tMultinomial const & m) const {
  return (! ((*this)==m) );
}
      
inline
int tMultinomial::size() const { return _n;}

inline
//void tMultinomial::getParams(int & n , double const * & p ) const { n=_n;p=_PR;}
double const * tMultinomial::getParams(int & n ) const { n=_n;return _PR;}
#endif










