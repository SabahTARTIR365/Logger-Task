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
//	cout << "hi test";
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

string Logger::getLableType()
{
	string label;
	switch (type) {
	case DEBUG: label = "DEBUG"; break;
	case INFO:  label = "INFO "; break;
	case WARN:  label = "WARN "; break;
	case ERROR: label = "ERROR"; break;
	case SILENT: label = "SILENT"; break;
		
	}
	return label;

	return string();
}







