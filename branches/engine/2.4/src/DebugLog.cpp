//
// File        : $RCSfile: $ 
//               $Workfile: DebugLog.cpp $
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

#include "DebugLog.h"

#include "core/Str.h"
#include "persistance/TextWriter.h"
#include "persistance/OutputStream.h"
#include "persistance/UnbufferedChannel.h"
#include "persistance/StdOutputStream.h"
#include <fstream>

boost::shared_ptr <Persistance::TextWriter> SeedSearcherLog::__textWriter;
boost::shared_ptr <Langauge> SeedSearcherLog::__langauge;

using namespace Persistance;
using namespace std;


void SeedSearcherLog::setupConsoleLogging (bool supress)
{   
   if (supress) {
      setup (boost::shared_ptr <TextWriter> (new TextWriter (new NullOutputStream ())));
   }
   else {
      UnbufferedOutput* console = new StdUnbufferedOutput (cout);
      SmallChannelOutput* output = new  SmallChannelOutput (console, true);
      Persistance::TextWriter* writer = 
         new Persistance::TextWriter (output, true); 

      setup (boost::shared_ptr <Persistance::TextWriter> (writer));
   }
}

void SeedSearcherLog::setupFileLogging (
   const StrBuffer& filename, bool suppressConsole)
{
   //
   // open the file
   ofstream* logOut = new ofstream;
   logOut->open (filename.getCString (), 
                  ios::out | ios::trunc | ios::binary);
   
   mmustbe ( logOut->is_open(), 
            StrBuffer (Str ("Cannot open logFile for "), filename));

   //
   // setup the channel to the file
   StdUnbufferedOutput* fileChannel = new StdUnbufferedOutput (logOut, true);

   if (!suppressConsole)   {
      //
      // setup a channel for the console
      StdUnbufferedOutput* consoleChannel = new StdUnbufferedOutput (cout);

      //
      // setup an output multiplexer
      Persistance::UnbufferedOutput* channels [] = 
         { consoleChannel, fileChannel };

      const int numOfChannels = 
         sizeof (channels) / sizeof (Persistance::UnbufferedOutput*);

      UnbufferedOutputMux* mux = 
         new UnbufferedOutputMux (channels, numOfChannels , true);

      //
      // setup output stream for the mux
      SmallChannelOutput* output = new SmallChannelOutput (mux, true);

      //
      // setup the writer
      Persistance::TextWriter* textWriter = new TextWriter (output, true);
      setup (boost::shared_ptr <Persistance::TextWriter> (textWriter));
   }
   else {
      //
      // setup output stream for the file
      SmallChannelOutput* output = new SmallChannelOutput (fileChannel, true);

      //
      // setup the writer
      TextWriter* textWriter = new TextWriter (output, true);
      setup (boost::shared_ptr <TextWriter> (textWriter));
   }
}





