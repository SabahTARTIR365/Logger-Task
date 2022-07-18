#include "Logger.h"
#include <fstream>
Logger* Logger::InstanceLogger = 0;
 bool Logger::isCommanded=true;
 Typelog Logger::type=INFO;



 void Logger::setLoggerType(Typelog type)
 {
	 this->type = type;
 }

 Logger* Logger::GetInstance()
{
	cout << "hi test";
	return (!InstanceLogger) ?
		InstanceLogger = new Logger() :
		InstanceLogger;
}

void Logger::setOutputFormat(bool isCommanded)
{
	this->isCommanded = isCommanded;
}

bool Logger::getOutputFormat()
{
	return this->isCommanded;
}

bool Logger::addToFile(string FileName, string Value)
{
	ofstream fout(FileName, ios::out);
	fout << Value << "\n";

	return false;
}







