#ifndef _SeedSearcher_PSSM_h
#define _SeedSearcher_PSSM_h

//
// File        : $RCSfile: $ 
//               $Workfile: PSSM.h $
// Version     : $Revision: 12 $ 
//               $Author: Aviad $
//               $Date: 10/01/05 1:55 $ 
// Description :
//    Concrete class for describing a PSSM
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
// and the library authors apply.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//


#include "Assignment.h"
#include "Alphabet.h"
#include "Sequence.h"
#include "SeqWeight.h"

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

  template <typename PrimType>
  void set (int n, PrimType pr []) {
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
  double _PR[ASSG_MAX_ALPHABET_SIZE];
};


class PSSM {
   //
   // this class is used late in the running of the program, when it
   // is often best to avoid dynamic memory allocations,
   // so it uses static buffers only
public:
   enum { MAX_PSSM_LENGTH = 32 };

   //
   // creates an empty pssm 
   PSSM () {
   }
   PSSM (PositionWeightType positionWeightType,
         const AlphabetCode& code,
	      int motifLength, int pssmLength,
         const PositionVector& posVec  ,
         const SeqWeightFunction& wf) {
     set (positionWeightType, code, motifLength, pssmLength, posVec, wf);
   }
   ~PSSM () {
   }

   //
   // create a PSSM from a vector of positions
   // 'length' is the length of the PSSM
   // 'offset' is the (often negative) 
   // offset from the position to start building
   void set (  PositionWeightType positionWeightType,
               const AlphabetCode& code, 
	            const int motifLength,
	            const int pssmLength,
               const PositionVector& posVec  ,
               const SeqWeightFunction& wf   ) 
   {
      _positionWeightType = positionWeightType;
      _length = pssmLength;
      double positions [MAX_PSSM_LENGTH][ASSG_MAX_ALPHABET_SIZE];
      memset (positions, 0, sizeof (positions));

      //
      // for all the places the motif exists
      CPositionIterator it (posVec.begin (), posVec.end ());
      for (; it.hasNext () ; it.next ()) {
         //
         // the following line is wrong, since it introduces offset errors
         // (*it)->getModifiedOffsets (myOffset, myLength);
         // the following line replaces it
         StrBuffer buf(_length);
         (*it)->getSeedString (buf,  motifLength, _length);
         const SeqPosition& position = *(*it);

         //
         // get the weight of the seq
         double weight = 0;
         switch (_positionWeightType)  {
            case _position_weight_discrete_: weight = 1; break;
            case _position_weight_real_:     
               weight = wf.weight(position.sequence()->id ());
               break;
            case _position_weight_hotspots_:
               weight = wf.weight(position, motifLength);
               break;
            default:
               mustfail ();
               break;
         };
          

         //
         // 
         for (int i=0; i<_length ; i++) {
         AlphabetCode::Char c = buf [i];
         if (c != SeqPosition::_DEFAULT_ALLIGNMENT_CHAR_) {
               AlphabetCode::CodedChar cc = code.code (c);
               //
               // keep gcc happy
               int cc_index = static_cast <int> (cc);
               positions [i][cc_index] += weight;
            }
         }
      }

      //
      //
      for (int i=0 ; i <_length ; i++) {
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
   PositionWeightType _positionWeightType;
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


#endif // _SeedSearcher_PSSM_h



