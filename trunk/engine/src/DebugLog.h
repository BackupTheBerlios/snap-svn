#ifndef _SeedSearcher_DebugLog_h
#define _SeedSearcher_DebugLog_h

//
// File        : $RCSfile: $ 
//               $Workfile: DebugLog.h $
// Version     : $Revision: 14 $ 
//               $Author: Aviad $
//               $Date: 23/08/04 21:44 $ 
// Description :
//    Concrete class for outputing useful debug information
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

#include "persistance/Defs.h"
#include "persistance/TextWriter.h"
#include "persistance/AbstractFormat.h"

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
      mustbe (__textWriter.get ());
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

private:
   static boost::shared_ptr <Persistance::TextWriter> __textWriter;
   static boost::shared_ptr <Langauge> __langauge;
};


#endif











