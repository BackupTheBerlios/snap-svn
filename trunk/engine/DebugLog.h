#ifndef _SeedSearcher_DebugLog_h
#define _SeedSearcher_DebugLog_h

#include "Persistance/Defs.h"
#include "Persistance/TextWriter.h"
#include "Persistance/AbstractFormat.h"

#include "AssignmentFormat.h"

#define DLOG SeedSearcherLog::writer ()

class SeedSearcherLog {
public:
   //
   // sets the writer used for logging
   static Persistance::TextWriter* setup (Persistance::TextWriter* in ) {
      Persistance::TextWriter* old = __textWriter;
      __textWriter = in;
      return old;
   }
   //
   // sets the 'data' langauge used for logging (for example ACGT langauge)
   static Langauge* setup (Langauge* in) {
      Langauge* old = __langauge;
      __langauge = in;
      return old;
   }
   inline static Persistance::TextWriter& writer () {
      debug_mustbe (__textWriter);
      return (*__textWriter);
   }
   static Langauge& assgWriter () {
      debug_mustbe (__langauge);
      return (*__langauge);
   }

   friend Persistance::AbstractFormat::Owner 
      Format (const Assignment& assg) {
      return new AssignmentFormat (assg, *__langauge);
   }

   friend Persistance::AbstractFormat::Owner 
      Format (const Assignment::Position& pos) {
      return new PositionFormat (pos, *__langauge);
   }

   //
   // this method setups a default logger.
   // if suppress==true the logger is null and no logging is performed
   // if suppress==false logging is performed to std output
   // the method returns the previous logger object
   static Persistance::TextWriter* setupConsoleLogging (bool supress);

   //
   // this method setup up file logging
   static Persistance::TextWriter* setupFileLogging (
      const StrBuffer& filename, bool supressConsole);

private:
   static Persistance::TextWriter* __textWriter;
   static Langauge* __langauge;
};


#endif











