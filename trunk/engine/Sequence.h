#ifndef _SeedSearcher_Sequence_h
#define _SeedSearcher_Sequence_h

#include "SequenceDB.h"

class SequenceDB::Sequence {
public:
   Sequence (ID id, const char* data, double wgt) :   _id (id), 
                                                      _data (data), 
                                                      _weight (wgt) {
   }
   int length () const {
      return _data.length ();
   }
   inline const std::string& data () const {
      return _data;
   }
   inline ID id () const {
      return _id;
   }
   inline double weight () const {
      return _weight;
   }
   std::string data (int startPos, int length) const {
      return std::string (_data, startPos, length);
   }


private:
	ID _id;
   std::string _data;
   double _weight;
};



class SequenceDB::Position {
public:
   //
   // ctor is called in a loop, so must be very effiecient
	inline Position (Sequence const * seq, int pos) :  _sequence (seq),
                                                      _position (pos) {
   }
   
   inline char operator [] (int index) const {
      return getData (index);
   }
   inline char getData (int index) const {
      debug_mustbe (index + _position < _sequence->length ());
      return _sequence->data () [index + _position];
   }
   //
   // how much data available ahead in the stream
   inline int maxLookahead () const {
      return _sequence->length () - _position;
   }
   const Sequence* sequence () const {
      return _sequence;
   }
   int position () const {
      return _position;
   }
   std::string getDataString (int length) const {
      return std::string (_sequence->data (), _position, length);
   }

private:
	Sequence const * _sequence;
	int _position;
};



#endif // _SeedSearcher_Sequence_h

