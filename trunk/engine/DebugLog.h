#ifndef _SeedSearcher_DebugLog_h
#define _SeedSearcher_DebugLog_h

#include "Persistance/Defs.h"
#include "Persistance/TextWriter.h"
#include "Persistance/AbstractFormat.h"

#include "AssignmentFormat.h"

#include "boost/shared_ptr.hpp"

#define DLOG SeedSearcherLog::writer ()

class SeedSearcherLog {
public:
   //
   // sets the writer used for logging
   static void setup (boost::shared_ptr<Persistance::TextWriter> in) {
      __textWriter = in;
   }
   //
   // sets the 'data' langauge used for logging (for example ACGT langauge)
   static void setup (boost::shared_ptr <Langauge> in) {
      __langauge = in;
   }
   inline static Persistance::TextWriter& writer () {
      debug_mustbe (__textWriter.get ());
      return (*__textWriter);
   }
   static Langauge& assgWriter () {
      debug_mustbe (__langauge.get ());
      return (*__langauge);
   }

   friend Persistance::AbstractFormat::Owner 
      Format (const AssignmentBase& assg) {
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
   static void setupConsoleLogging (bool supress);

   //
   // this method setup up file logging
   static void setupFileLogging (
      const StrBuffer& filename, bool supressConsole);

   class Sentry {
   public:
      Sentry (bool suppressConsole = false) {
         SeedSearcherLog::setupConsoleLogging (suppressConsole);
      }
      ~Sentry () {
         SeedSearcherLog::setup (boost::shared_ptr <Persistance::TextWriter> ());
      }
      void setupFileLogging (const StrBuffer& filename, bool suppressConsole = false) {
         SeedSearcherLog::setupFileLogging (filename, suppressConsole);
      }
   };

private:
   static boost::shared_ptr <Persistance::TextWriter> __textWriter;
   static boost::shared_ptr <Langauge> __langauge;
};


#endif











