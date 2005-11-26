#ifndef __BASE_STATUS_REPORTER_H__
#define __BASE_STATUS_REPORTER_H__

/*
   BaseStatusReporter.hpp

   Author: Jeremy Moskovich

   Abstract base class for progress reporting.
*/

class BaseStatusReporter {
protected:
   enum JobStatus {
      NULL_STATUS             = 0,
      PROCESSING_ERROR_STATUS = 1, //an error occured while processing
      PROCESSING_STATUS       = 2,
      CANCELLED_STATUS        = 3,
      DONE_STATUS             = 4
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
};

#include "boost/shared_ptr.hpp"

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
      int percentDone = (100 * ++_progressPoints) / _maxProgressPoints;
      if (_reporter) _reporter->setProgress (percentDone);
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
private:
   static int _progressPoints;
   static int _maxProgressPoints;
   static boost::shared_ptr <BaseStatusReporter> _reporter;
};


#endif __BASE_STATUS_REPORTER_H__
