#include <iostream>

using namespace std;

#include "StatusReporter.hpp"

StatusReporter::StatusReporter( const char * inHost, 
		const char *  inDBName, 
		const char *  inUserName,
		const char *  inPassword,
		int 		  inJobID ) : 
		mJobID(inJobID), mUserCancelled(false) {


	strcpy( mHostName, inHost );
	strcpy( mDBName, inDBName );
	strcpy( mUserName, inUserName );
	strcpy( mPassword, inPassword );
}


StatusReporter::~StatusReporter() {
}

bool 
StatusReporter::hasUserCancelled() {

	//no point in querying if we already know the user
	//has cancelled
	if( !mUserCancelled ) {
	
		char query[256];
			
		connect();
		
		sprintf( query, "SELECT cancel_flag from jobs where id='%d'", mJobID );
		
		if( mysql_query( &mSQLObj, query ) ) {
			cout << "query failed\n";
			return false;
		}
		
		MYSQL_RES *result = mysql_use_result( &mSQLObj );
		
		MYSQL_ROW row = mysql_fetch_row(result);
		
		if( row == 0 ) {
			cout << "Error cancel_flag from DB!!!\n";
			return false;
		}
		
		mUserCancelled = (*(row[0]) == '1');
		
		disconnect();
		
	}
		
		
	return mUserCancelled;
}

void 
StatusReporter::setProgress( int inPercentDone ) {

	char query[256];

	connect();
	
	sprintf( query, "UPDATE JOBS SET percent_done='%d', last_update_ts=NOW() WHERE id='%d'", 
				inPercentDone, mJobID );
	
	if( mysql_query( &mSQLObj, query ) ) {
		cout << "update progress failed\n";
		return;
	}
	
	disconnect();

}

void 
StatusReporter::setJobStarted()
{
	setJobStatus(PROCESSING_STATUS);
}

void 
StatusReporter::setJobCancelled() {
	setJobStatus(CANCELLED_STATUS);
}

void 
StatusReporter::setJobDone() {
	setJobStatus(DONE_STATUS);
}

void
StatusReporter::connect()
{

	if( !mysql_init(&mSQLObj) ) {
		cout << "init MYSQL failed!\n";
		return;
	}
	
	if( !mysql_real_connect(&mSQLObj, mHostName, mUserName, mPassword, mDBName, 0, NULL, 0) ) {
		cout << "error connecting to mysql\n";
		return;
	}

}

void 
StatusReporter::setJobStatus( JobStatus inStatus )
{

	char query[256];

	connect();
	
	sprintf( query, "UPDATE JOBS SET job_status='%d' WHERE id='%d'", inStatus, mJobID );
	
	if( mysql_query( &mSQLObj, query ) ) {
		cout << "update status failed\n";
		return;
	}
	
	disconnect();

}

void 
StatusReporter::disconnect()
{
	mysql_close( &mSQLObj );
}
