#include <iostream>

#include "core/Defs.h"

using namespace std;

#include "DummyStatusReporter.hpp"

DummyStatusReporter::DummyStatusReporter( const char * inHost, 
		const char *  inDBName, 
		const char *  inUserName,
		const char *  inPassword,
		int 		  inJobID ) {
}


DummyStatusReporter::~DummyStatusReporter() 
{
}

bool 
DummyStatusReporter::hasUserCancelled() 
{
	return false;
}

void 
DummyStatusReporter::setProgress( int inPercentDone ) 
{
   debug_only (
	   cout << "Progress: " << inPercentDone << "\n";
   );
}

void 
DummyStatusReporter::setJobStarted()
{
   debug_only (cout << "STATUS: job started\n";);
}

void 
DummyStatusReporter::setJobCancelled() {
	debug_only (
      cout << "STATUS: job cancelled\n";
   );
}

void 
DummyStatusReporter::setJobDone() 
{
   debug_only (
	   cout << "STATUS: job DONE!\n";
   );
}

void 
DummyStatusReporter::setJobError(const Str& s)
{
   debug_only (
      cout << "STATUS: job ERROR! " << s.getChars () << endl;
   );
}



StatusReportManager::Sentry::Sentry( int argc, char **argv, Argv &outArgv )
{
   outArgv = Argv( argc, argv );

   StatusReportManager::setup (
      boost::shared_ptr <BaseStatusReporter> (
         new DummyStatusReporter (NULL, NULL, NULL, NULL, 0)
         )
      );
}
