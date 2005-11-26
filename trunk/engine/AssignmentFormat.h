#ifndef _SeedSearcher_AssignmentFormat_h
#define _SeedSearcher_AssignmentFormat_h

#include "Assignment.h"
#include "Persistance/Defs.h"
#include "Persistance/AbstractFormat.h"

#include "Core/Str.h"

//
//
class Langauge {
public:
   //
   // return the code of the langauge
   virtual const AlphabetCode& code () const = 0;
   
   //
   // convert assignment position to text,
   // used to display search results
   virtual void write ( const Assignment::Position&, 
                        Persistance::TextWriter&) const = 0;

   Persistance::AbstractFormat::Owner format (const Assignment& assg) const;
   Persistance::AbstractFormat::Owner format (const Assignment::Position& pos) const;

   //
   // return a wildcard with the appropriate strategy (for searching)
   virtual Assignment::Position wildcard (Assignment::Strategy) const = 0;

   //
   // performs comparison on the strings.
   // returns 0 if they are 'identical' in terms of the langauge
   // returns a negative result if a is 'before' b
   // returns a positive result if b is 'before' a
   virtual int compare (const Str& a, const Str& b) const {
      return a.compareIgnoreCase (b);
   }

   //
   // returns the complement of an assignemnt 
   // (for instance the reverse assignment for ACGT langugaue)
   virtual void complement (const Assignment& in, Assignment& out) const {
      out = in;
   }

   //
   // returns the complement of word in the langauge
   // (for instance the reverse kmer for ACGT langugaue)
   virtual void complement (const Str& in, StrBuffer& out) const {
      out= in;
   }

   //
   // returns true if complements are supported for this langauge
   virtual bool supportComplement () const {
      return false;
   }
};


//
//
class AssignmentFormat : public Persistance::AbstractFormat {
public:
   AssignmentFormat (const Assignment& a, const Langauge& langauge) 
      : _assg (a), _langauge (langauge) {
   }
   virtual void write (Persistance::TextWriter& out) const {
      int length = _assg.length ();
      for (int i=0 ; i<length ; i++)
         _langauge.write (_assg[i], out);
   }

private:
   const Assignment& _assg;
   const Langauge& _langauge;
};


//
//
class PositionFormat : public Persistance::AbstractFormat {
public:
   PositionFormat (const Assignment::Position& a, const Langauge& writer) 
      : _pos (a), _writer (writer) {
   }
   virtual void write (Persistance::TextWriter& out) const {
      _writer.write (_pos, out);
   }

private:
   const Assignment::Position& _pos;
   const Langauge& _writer;
};

 
inline Persistance::AbstractFormat::Owner 
   Langauge::format (const Assignment& assg) const {
      return new AssignmentFormat (assg, *this);
}

inline Persistance::AbstractFormat::Owner 
   Langauge::format (const Assignment::Position& pos) const {
      return new PositionFormat (pos, *this);
}

#endif // _SeedSearcher_AssignmentFormat_h


