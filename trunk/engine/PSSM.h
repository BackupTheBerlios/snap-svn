#include "Assignment.h"
#include "PrefixTreePreprocessor.h"



#include <iostream>
#include <vector>
#include <string>


//
// Adapted from Legacy SeedSearcher
class Multinomial {
public:
  Multinomial();
  Multinomial(int n);
  Multinomial(const std::vector<double>&, const bool isExp);
  Multinomial(const Multinomial& );
  Multinomial operator=( const Multinomial& );
  bool operator==( const Multinomial& ) const;
  bool operator!=( const Multinomial& )const;

  void set (int n, int pr []) {
     _n = n;
     for (int i=0 ; i<n ; i++) {
        _PR [i] = pr [i];
     }

     Normalize ();
  }
  
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
  
//  friend ostream& operator<<(ostream&, Multinomial const&);

//  void Read( istream& );

  int MAP() const;
  
  /**
   * its the user reponsibility to use it on normallized dist only.
   * also note the user should avoid using it with prob of 0 in one of the values.
   * the multinomials themselves should be of the same size. 
   */
  double KL(Multinomial const & m) const ;
  
 private:
  int _n; 
  double _PR[Assignment::MAX_ALPHABET_SIZE];
};


class PSSM {
   //
   // this class is used late in the running of the program, when it
   // is often best to avoid dynamic memory allocations,
   // so it uses static buffers only
public:
   enum { MAX_PSSM_LENGTH = 32 };
/*
   PSSM (const Assignment& assg, const PrefixTreePreprocessor& tree) {
      PrefixTreeWalker::Nodes nodes;
      nodes.addAssignmentNodes (tree, assg);

      set (

   }*/
   
   PSSM (const AlphabetCode& code, 
         int offset, 
         int length, 
         const PositionVector& posVec) {
      set (code, offset, length, posVec);
   }
   ~PSSM () {
   }

   //
   // create a PSSM from a vector of positions
   // 'length' is the length of the PSSM
   // 'offset' is the (often negative) offset from the position to start building
   void set (  const AlphabetCode& code, 
               const int offset, 
               const int length, 
               const PositionVector& posVec) 
   {
      _length = length;
      //
      // TODO: support partial counts?
      // TODO: count positive positions only, or all positions?
      int positions [MAX_PSSM_LENGTH][Assignment::MAX_ALPHABET_SIZE];
      memset (positions, 0, sizeof (positions));

      //
      // TODO: what should I do when 

      //
      // for all the places the motif exists
      CPositionIterator it (posVec.begin (), posVec.end ());
      for (; it.hasNext () ; it.next ()) {
         //
         // go over all positions
         int myOffset = offset;
         int myLength = length;
         (*it)->getModifiedOffsets (myOffset, myLength);

         for (int i=0; i<myLength ; i++) {
            AlphabetCode::Char c = (*it)->getData(myOffset++);
            AlphabetCode::CodedChar cc = code.code (c);
            positions [i][cc]++;
         }
      }

      //
      //
      for (int i=0 ; i <length ; i++) {
         _positionScores [i].set (code.cardinality (), positions [i]);
      }
   }

   int length () const {
      return _length;
   }
   const Multinomial& get (int i) const {
      debug_mustbe (i>=0);
      debug_mustbe (i<_length);

      return _positionScores [i];
   }
   const Multinomial& operator [] (int i) const {
      return get (i);
   }

private:
   int _length;
   Multinomial _positionScores [MAX_PSSM_LENGTH];
};

inline
double
Multinomial::operator[]( int i ) const
{
  return _PR[i];
}

inline
double&
Multinomial::operator[]( int i ) 
{
  return _PR[i];
}

inline
bool Multinomial::operator==(Multinomial const & m) const {
  if(_n != m._n) return false;
  for (int i =0;i<_n;i++)
    if (_PR[i]!=m._PR[i]) return false;
  return true;
}

inline
bool Multinomial::operator!=(Multinomial const & m) const {
  return (! ((*this)==m) );
}
      
inline
int Multinomial::size() const { return _n;}

inline
//void Multinomial::getParams(int & n , double const * & p ) const { n=_n;p=_PR;}
double const * Multinomial::getParams(int & n ) const { n=_n;return _PR;}











