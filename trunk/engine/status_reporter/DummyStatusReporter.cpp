#include <iostream>

using namespace std;

#include "DummyStatusReporter.hpp"

DummyStatusReporter::DummyStatusReporter( const char * inHost, 
		const char *  inDBName, 
		const char *  inUserName,
		const char *  inPassword,
		int 		  inJobID ) {
}


DummyStatusReporter::~DummyStatusReporter() {
}

bool 
DummyStatusReporter::hasUserCancelled() {

	return false;
}

void 
DummyStatusReporter::setProgress( int inPercentDone ) {

	cout << "Progress: " << inPercentDone << "\n";

}

void 
DummyStatusReporter::setJobStarted()
{
	cout << "STATUS: job started\n";
}

void 
DummyStatusReporter::setJobCancelled() {
	cout << "STATUS: job cancelled\n";
}

void 
DummyStatusReporter::setJobDone() {
	cout << "STATUS: job DONE!\n";
}
