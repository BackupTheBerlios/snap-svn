#ifndef _SeedSearcher_AssignmentFormat_h
#define _SeedSearcher_AssignmentFormat_h

//
// File        : $RCSfile: $ 
//               $Workfile: AssignmentFormat.h $
// Version     : $Revision: 12 $ 
//               $Author: Aviad $
//               $Date: 13/10/04 3:33 $ 
// Description :
//    interface classes for the formatting and structure of assignments.
//    of special importance is the Langauge idiom.
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

#include "Assignment.h"
#include "persistance/Defs.h"
#include "persistance/AbstractFormat.h"

#include "core/Str.h"

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

   virtual Assignment& stringToAssignment (Assignment& motif, const Str& motif_str) const{
      return motif;
   }

   virtual int cardinality () const = 0;
};


//
//
class AssignmentFormat : public Persistance::AbstractFormat {
public:
   AssignmentFormat (const AssignmentBase& a, const Langauge& langauge) 
      : _assg (a), _langauge (langauge) {
   }
   virtual void write (Persistance::TextWriter& out) const {
      int length = _assg.length ();
      for (int i=0 ; i<length ; i++)
         _langauge.write (_assg[i], out);
   }

private:
   const AssignmentBase& _assg;
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


