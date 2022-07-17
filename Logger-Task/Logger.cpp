#include "Logger.h"
Logger* Logger::InstanceLogger = 0;

Logger* Logger::GetInstance()
{
	cout << "hi test";
	return (!InstanceLogger) ?
		InstanceLogger = new Logger :
		InstanceLogger;
}
