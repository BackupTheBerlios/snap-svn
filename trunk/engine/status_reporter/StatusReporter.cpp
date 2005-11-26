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
	
	mPid = getpid();
	
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
		
		if( mysql_query( &mSQLObj, query ) ) { //fatal?
			throw StatusException( "query failed\n" );
		}
		
		MYSQL_RES *result = mysql_use_result( &mSQLObj );
		
		MYSQL_ROW row = mysql_fetch_row(result);
		
		if( row == 0 ) {
			throw StatusException(  "StatusReporter::hasUserCancelled - Error "
						"couldn't retrieve row cancel_flag from DB!!!\n" );
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
		throw StatusException(  "StatusReporter::setProgress update progress failed\n" );
		return;
	}
	
	disconnect();

}

void 
StatusReporter::setJobStarted()
{
	char query[256];

	connect();
	
	sprintf( query, "UPDATE JOBS SET job_status='%d', pid='%d', start_time=now() WHERE id='%d'", 
														PROCESSING_STATUS, mPid, mJobID );
	
	if( mysql_query( &mSQLObj, query ) ) {
		throw StatusException( "update status failed\n" );
	}
	
	disconnect();
}

void 
StatusReporter::setJobCancelled() {
	setJobStatus(CANCELLED_STATUS, true);
}

void 
StatusReporter::setJobDone() {
	setJobStatus(DONE_STATUS, true);
}

void
StatusReporter::connect()
{

	if( !mysql_init(&mSQLObj) ) {
		throw StatusException( "init MYSQL failed!\n" );
	}
	
	if( !mysql_real_connect(&mSQLObj, mHostName, mUserName, mPassword, mDBName, 0, NULL, 0) ) {
		throw StatusException( "error connecting to mysql\n" );
	}

}

void 
StatusReporter::setJobStatus( JobStatus inStatus, bool inSetEndTime )
{

	char query[256];

	connect();
	
	if( inSetEndTime )
		sprintf( query, "UPDATE JOBS SET job_status='%d',  "
		" end_time = now() WHERE id='%d'", inStatus, mJobID );
	else
		sprintf( query, "UPDATE JOBS SET job_status='%d' WHERE id='%d'", 
														inStatus, mJobID );
	
	if( mysql_query( &mSQLObj, query ) ) {
		throw StatusException( "update status failed\n" );
	}
	
	disconnect();

}

void 
StatusReporter::disconnect()
{
	mysql_close( &mSQLObj );
}


{


StatusReportManager::Sentry::Sentry( int argc, char **argv, Argv &outArgv )
{
   printf("\nConnecting to DB...\n");
   /* 
   In Server mode, the first parameters on the command
   line are: db_host, db_name, db_user, db_pass, job_id
   then come all the usual seed parameters
   */
   const char *db_host = argv[1];
   const char *db_name = argv[2];
   const char *db_user = argv[3];
   const char *db_pass = argv[4];
   int job_id = atoi( argv[5] );

   printf("Arguments: (%s) (%s) (%s) (%s) (%d)\n", db_host, db_name,
      db_user, db_pass, job_id);

   outArgv.set( argv[0], argc-6, argv+6 );

   //
   // setup the status report manager
   StatusReportManager::setup (
      boost::shared_ptr <BaseStatusReporter> (
         new StatusReporter (db_host, db_name, db_user, db_pass, job_id)

#				endif
      )
      );

   StatusReportManager::setJobStarted ();
}
~auto_report () {
   StatusReportManager::setJobDone ();
}
