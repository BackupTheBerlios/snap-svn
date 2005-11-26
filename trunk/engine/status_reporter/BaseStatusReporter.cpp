#include "BaseStatusReporter.hpp"

boost::shared_ptr <BaseStatusReporter> StatusReportManager::_reporter;
int StatusReportManager::_progressPoints = 0;
int StatusReportManager::_maxProgressPoints = 0;

BaseStatusReporter::StatusException::StatusException( const Str &inErrString ) :
	mErrString( inErrString )
{	
}

void BaseStatusReporter::StatusException::explain( std::ostream &outStr )
{
	outStr << mErrString;
}
