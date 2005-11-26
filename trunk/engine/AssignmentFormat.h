#ifndef _SeedSearcher_AssignmentFormat_h
#define _SeedSearcher_AssignmentFormat_h

#include "Assignment.h"
#include "Persistance/Defs.h"
#include "Persistance/AbstractFormat.h"

//
//
class AssignmentWriter {
public:
   virtual ~AssignmentWriter () {
   };

   virtual void write (const Assignment::Position&, Persistance::TextWriter&) const= 0;
};



//
//
class AssignmentFormat : public Persistance::AbstractFormat {
public:
   AssignmentFormat (const Assignment& a, AssignmentWriter& writer) 
      : _assg (a), _writer (writer) {
   }
   virtual void write (Persistance::TextWriter& out) const {
      int length = _assg.length ();
      for (int i=0 ; i<length ; i++)
         _writer.write (_assg[i], out);
   }

private:
   const Assignment& _assg;
   AssignmentWriter& _writer;
};


//
//
class PositionFormat : public Persistance::AbstractFormat {
public:
   PositionFormat (const Assignment::Position& a, AssignmentWriter& writer) 
      : _pos (a), _writer (writer) {
   }
   virtual void write (Persistance::TextWriter& out) const {
      _writer.write (_pos, out);
   }

private:
   const Assignment::Position& _pos;
   AssignmentWriter& _writer;
};


#endif // _SeedSearcher_AssignmentFormat_h











