#ifndef __BASE_STATUS_REPORTER_H__
#define __BASE_STATUS_REPORTER_H__

/*
   BaseStatusReporter.hpp

   Author: Jeremy Moskovich

   Abstract base class for progress reporting.
*/

#include "boost/shared_ptr.hpp"
#include "core/Defs.h"
#include "core/Str.h"
#include "core/Argv.h"

class BaseStatusReporter {
protected:
   enum JobStatus {
	NULL_STATUS             = 0,
	PROCESSING_STATUS       = 2,
	CANCEL_REQUEST_STATUS   = 6,//the process accepted the cancel request
	CANCELLED_STATUS        = 7,
	DONE_STATUS             = 3,
	PROCESSING_ERROR_STATUS = 8 //an error occured while processing
		
   };

public:
   virtual ~BaseStatusReporter () {
   }

   //returns true if user has requested that the job be cancelled
   virtual bool hasUserCancelled() = 0;

   //updates progress field in database, parameter is an int
   //assuming a value of 0-100
   virtual void setProgress( int inPercentDone ) = 0;

   //call when processing starts on the job
   virtual void setJobStarted() = 0;

   //call once job was succesfully cancelled
   virtual void setJobCancelled() = 0;

   //call when job is completed
   virtual void setJobDone() = 0;

   //call when job is stopped because of error
   virtual void setJobError(const Str&) = 0;

   struct StatusException : public BaseException {
     StatusException() {
     }
     StatusException( const Str &inErrString ) 
     {
       inErrString.getCString (_message);
     }
     ~StatusException () throw () {
     }
   };

   struct CancelledException : public StatusException {
     ~CancelledException () throw () {
     }
   };
};


//Aviad's Singleton Manager

struct StatusReportManager {
   //
   // setup the global reporter
   static void setup (boost::shared_ptr <BaseStatusReporter> in)
   {
      _reporter = in;
   }
   static void setMaxProgress (int inMaxProgressPoints) {
      _progressPoints = 0;
      _maxProgressPoints = inMaxProgressPoints;
   }
   static boost::shared_ptr <BaseStatusReporter> getInstance () {
      return _reporter;
   }


   //returns true if user has requested that the job be cancelled
   static inline bool hasUserCancelled() {
      return (_reporter)? _reporter->hasUserCancelled () : false;
   }

   //updates progress field in database, parameter is an int
   //assuming a value of 0-100
   static inline void setProgress( int inPercentDone) {
      if (_reporter) _reporter->setProgress (inPercentDone);
   }
   static inline void setProgress() {
		++_progressPoints;
		if (_reporter) {
			int percentDone = (100 * _progressPoints) / _maxProgressPoints;
			_reporter->setProgress (percentDone); 
		}
   }

   //call when processing starts on the job
   static inline void setJobStarted() {
      if (_reporter) _reporter->setJobStarted ();
   }

   //call once job was succesfully cancelled
   static inline void setJobCancelled() {
       if (_reporter) _reporter->setJobCancelled ();
   }

   //call when job is completed
   static inline void setJobDone() {
      if (_reporter) _reporter->setJobDone ();
   }

   //call when job is completed
   static inline void setJobError(const Str& s) {
      if (_reporter) _reporter->setJobError (s);
   }

   struct Sentry {
      Sentry ( int argc, char **argv, Argv &outArgv );
      ~Sentry () {
      }
   };

private:
   static int _progressPoints;
   static int _maxProgressPoints;
   static boost::shared_ptr <BaseStatusReporter> _reporter;
};

#endif //__BASE_STATUS_REPORTER_H__

