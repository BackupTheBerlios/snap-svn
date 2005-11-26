#include "BaseStatusReporter.hpp"

boost::shared_ptr <BaseStatusReporter> StatusReportManager::_reporter;
int StatusReportManager::_progressPoints = 0;
int StatusReportManager::_maxProgressPoints = 0;

