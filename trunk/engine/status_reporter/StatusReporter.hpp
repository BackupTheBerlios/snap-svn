#ifndef __STATUS_REPORTER_H__
#define __STATUS_REPORTER_H__

/*
	StatusReporter.hpp

	Author: Jeremy Moskovich
	
	A class that provides progress reporting, job status and user
	interaction while a job is running.

	The class currently interfaces with a MySQL database to provide remote
	user control and status display.
	
	TODO:
		1)Adopt project data types and coding conventions.
		2)Adopt project error reporting standards w/special attention
		for fatal error handling.
		3)Pass job id to object.
		4)Configure db name and password.
*/

#include "/sw/include/mysql/mysql.h"
#include "BaseStatusReporter.hpp"

class StatusReporter : public BaseStatusReporter {

protected:
	char  mHostName[256];
	char  mDBName[256];
	char  mUserName[256];
	char  mPassword[256];
	int   mJobID;
	pid_t mPid;
	bool  mUserCancelled;
	
	MYSQL mSQLObj;

public:
	//Constructor - input required parameters to
	//connect to DB server
	StatusReporter( const char * inHost, 
		const char *  inDBName, 
		const char *  inUserName,
		const char *  inPassword,
		int 		  inJobID );

	//destructor
	virtual ~StatusReporter();

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
	void setJobStatus( JobStatus inStatus, bool inSetEndTime );
	void disconnect();

};


#endif //__STATUS_REPORTER_H__