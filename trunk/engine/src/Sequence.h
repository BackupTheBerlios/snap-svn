#ifndef _SeedSearcher_Sequence_h
#define _SeedSearcher_Sequence_h

//
// File        : $RCSfile: $
//               $Workfile: Sequence.h $
// Version     : $Revision: 34 $
//               $Author: Aviad $
//               $Date: 13/05/05 11:12 $
// Description :
//    Concrete classes for sequences, sequence positions
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
// and the library authors appliy.
// see http://www.cs.huji.ac.il/labs/compbio/LibB/LICENSE
//

#include "Defs.h"
#include "core/STLHelper.h"
#include "core/Str.h"

class Sequence {
public:
   typedef int ID;
   typedef StrBuffer Name;

   Sequence (ID id,
            const Str& data,
            const Str& name,
            Str reverse = NULL)
   : _id (id), _data (data), _reverse (reverse),
     _name (name)
   {
      debug_mustbe ((reverse.length () == 0) || 
                    (reverse.length () == data.length ()));
   }
   ~Sequence () {
   }
   int length () const {
      return _data.length ();
   }
   inline const Str& data (Strand strand = _strand_pos_) const {
      if (strand == _strand_pos_)
         return _data;
      else return _reverse;
   }
   inline ID id () const {
      return _id;
   }
   const Name& name () const {
      return _name;
   }
   Str data (int startPos, int length, Strand strand = _strand_pos_) const {
      return Str (data (strand), startPos, startPos + length);
   }

private:
   ID _id;
   StrBuffer _data;
   StrBuffer _reverse;
   Name _name;
};


class SeqPosition {
public:
  enum {
    _DEFAULT_ALLIGNMENT_CHAR_ = '-'
  };

public:
   //
   // ctor is called in a loop, so must be very efficient
   inline SeqPosition (Sequence const * seq, int pos)
   :  _sequence (seq), _position (pos), _strand (_strand_pos_) {
   }
   inline SeqPosition (Sequence const * seq, int pos, Strand strand)
   :  _sequence (seq), _position (pos), _strand (strand) {
   }
   ~SeqPosition () {
   }

   inline char operator [] (int index) const {
      return getData (index);
   }
   inline char getData (int index) const {
      debug_mustbe (index + _position < _sequence->length ());
      return _sequence->data (_strand) [index + _position];
   }
   //
   // how much data available ahead in the stream
   inline int maxLookahead () const {
      return _sequence->length () - _position;
   }
   const Sequence* sequence () const {
      return _sequence;
   }
   //
   // returns the offset in the sequence (unmodified by strand)
   int position () const {
      return _position;
   }
   Strand strand () const {
      return _strand;
   }

	enum OffsetFrom {
		_offset_from_beginning_,
		_offset_from_end_
	};

   //
   // returns the offset from the end of the sequence.
	// the last character of the sequence is assumed to be -1 upstream
	// from the TSS of the gene
   int tssPosition (int motifLength, OffsetFrom offsetFrom = _offset_from_end_) const {
		debug_mustbe (motifLength >= 0);
		debug_mustbe (motifLength <= maxLookahead ());

		// ---> strand with gene   TSS 
		//							 *		|	the motif AACCG lies -5 to 0 upstream
		//		TGAA...		 ...AACCG| --> the gene
		//		ACTT...		 ...TTGGC|		the gene complement	<--
		//								  *|  the motif CGGTT lies 0 to -5 upstream
		//										<--- reverse of the strand with the gene
		if (offsetFrom == _offset_from_end_) {
			if (_strand == _strand_pos_)
				return (- maxLookahead());
			else
				return -position () - motifLength;
		}
		else {
			if (_strand == _strand_pos_)
				return position ();
			else {
				return maxLookahead () - motifLength;
			}
		}
	}

	//
   // returns the sequence string starting at this position,
   // modified by 'offset'with length 'length'.
   // if offset is too big or too small (negative)
   // it will return a shorter string. in any case, it always returns
   // a valid string.
   Str getSeedString (int seedLength, int offset = 0) const;

   //
   // 'expands' a motif of length 'inLength' leftwards and rightwards,
   // in the desired amount. it adds alignment bytes if necessary.
   // returns the index of the beginning of the middle section
   int getSeedString (StrBuffer& outBuffer,  // the string is stored here
                      int inLength,          // desired length
                      int inDesiredExpansionLeft,
                      int inDesiredExpansionRight,
                      char alignment = _DEFAULT_ALLIGNMENT_CHAR_
            // alignment for missing pos
                      ) const;

   int getSeedString (  StrBuffer& outBuffer,
                        int inLength,  // length of seed before expansion
                        int inDesiredLength,  // length after expansion
                        char alignment = '-'  // alignment for missing pos
                        ) const;

   //
   //
   static int getSeedString (
                        Sequence const* sequence,
                        int position,
              Strand strand,
              StrBuffer& outBuffer,
              int inLength, // length of seed before expansion
              int inDesiredLength, // length after expansion
              char alignment = _DEFAULT_ALLIGNMENT_CHAR_
              // alignment for missing pos
                        );

   //
   // the 1st argument (in/out) provides the offset from this position
   // the 2nd argument (in/out) provides the length from the offset
   //
   // this method makes changes the offset (if necessary) so
   // that it is legal, decreasing the length in accordance.
   // also if the length is too large, it is decreased.
   void getModifiedOffsets (int& offset, int& length) const;

private:
   Sequence const * _sequence;
   int _position;
   Strand _strand;
};

//
// a vector of sequences
typedef Vec <Sequence const*> SequenceVector;

//
// a vector of positions
class PositionVector : public Vec <SeqPosition const*>
{
public:
   PositionVector () {
   }
   ~PositionVector () {
   }
};

//
// iterators
typedef IteratorWrapper <PositionVector> PositionIterator;
typedef IteratorWrapper <SequenceVector> SequenceIterator;
typedef CIteratorWrapper <PositionVector> CPositionIterator;
typedef CIteratorWrapper <SequenceVector> CSequenceIterator;




#endif // _SeedSearcher_Sequence_h













