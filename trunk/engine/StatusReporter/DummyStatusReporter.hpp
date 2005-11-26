#ifndef __DUMMY_TATUS_REPORTER_H__
#define __DUMMY_STATUS_REPORTER_H__

/*
   DummyStatusReporter.hpp

   Author: Jeremy Moskovich

   A dummy implementation of the status reporter class that
   presents output to stdout and doesn't link with MySQL.
*/

#include "BaseStatusReporter.hpp"

class DummyStatusReporter : public BaseStatusReporter
{

public:
   //Constructor - input required parameters to
   //connect to DB server
   DummyStatusReporter( const char * inHost,
      const char *  inDBName,
      const char *  inUserName,
      const char *  inPassword,
      int        inJobID );

   //destructor
   virtual ~DummyStatusReporter();

   //returns true if user has requested that the job be cancelled
   bool hasUserCancelled();

   //updates progress field in database, parameter is an int
   //assuming a value of 0-100
   void setProgress( int inPercentDone );

   //call when processing starts on the job
   void setJobStarted();

   //call once job was succesfully cancelled
   void setJobCancelled();

   //call when job is completed
   void setJobDone();

protected:
   void connect();
   void setJobStatus( JobStatus inStatus );
   void disconnect();

};


#endif __DUMMY_TATUS_REPORTER_H__
