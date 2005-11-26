#ifndef _SeedSearcher_DebugLog_h
#define _SeedSearcher_Defs_h

#include "Persistance/Defs.h"
#include "Persistance/TextWriter.h"
#include "Persistance/AbstractFormat.h"

#include "Assignment.h"

#define DLOG DebugLog::writer ()

class DebugLog {
public:
   static void setup (Persistance::TextWriter& in ) {
      __textWriter = &in;
   }
   static void setup (Assignment::Writer& in) {
      __assgWriter = &in;
   }
   inline static Persistance::TextWriter& writer () {
      debug_mustbe (__textWriter);
      return (*__textWriter);
   }
   static Assignment::Writer& assgWriter () {
      debug_mustbe (__assgWriter);
      return (*__assgWriter);
   }

   //
   struct AssignmentFormat : public Persistance::AbstractFormat {
      AssignmentFormat (const Assignment& a, Assignment::Writer& writer) 
         : _assg (a), _writer (writer) {
      }
      virtual void write (Persistance::TextWriter& out) {
         int length = _assg.length ();
         for (int i=0 ; i<length ; i++)
            _writer.write (_assg[i], out);
      }

      const Assignment& _assg;
      Assignment::Writer& _writer;
   };

   //
   struct PositionFormat : public Persistance::AbstractFormat {
      PositionFormat (const Assignment::Position& a, Assignment::Writer& writer) 
         : _pos (a), _writer (writer) {
      }
      virtual void write (Persistance::TextWriter& out) {
         _writer.write (_pos, out);
      }

      const Assignment::Position& _pos;
      Assignment::Writer& _writer;
   };



   friend Persistance::AbstractFormat::Owner 
      Format (const Assignment& assg) {
      return new AssignmentFormat (assg, *__assgWriter);
   }

   friend Persistance::AbstractFormat::Owner 
      Format (const Assignment::Position& pos) {
      return new PositionFormat (pos, *__assgWriter);
   }

private:
   static Persistance::TextWriter* __textWriter;
   static Assignment::Writer* __assgWriter;
};


#endif