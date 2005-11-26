#ifndef _SeedSearcher_DebugLog_h
#define _SeedSearcher_DebugLog_h

#include "Persistance/Defs.h"
#include "Persistance/TextWriter.h"
#include "Persistance/AbstractFormat.h"

#include "AssignmentFormat.h"

#define DLOG SeedSearcherLog::writer ()

class SeedSearcherLog {
public:
   static void setup (Persistance::TextWriter& in ) {
      __textWriter = &in;
   }
   static void setup (AssignmentWriter& in) {
      __assgWriter = &in;
   }
   inline static Persistance::TextWriter& writer () {
      debug_mustbe (__textWriter);
      return (*__textWriter);
   }
   static AssignmentWriter& assgWriter () {
      debug_mustbe (__assgWriter);
      return (*__assgWriter);
   }

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
   static AssignmentWriter* __assgWriter;
};


#endif










