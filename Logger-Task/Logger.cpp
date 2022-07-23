#include "Logger.h"
#include <fstream>

Logger* Logger::InstanceLogger = 0;
 bool Logger::_isConsoleOutput =true;
 bool Logger::_isFileOutput = true;

 Typelog Logger::type=INFO;

// template Logger& operator << (Logger& log, const string const value);
 template Logger& operator << (Logger& log, int const value);
 template Logger& operator << (Logger& log, double const value);
 template Logger& operator << (Logger& log,  const char * const value);


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

void Logger::setConsoleFormatOutput(bool  isConsoled)
{ 
	cout << "here I'm in console output";
	this->_isConsoleOutput = isConsoled;
}

void Logger::setFileFormatOutput(bool isFiled)
{
	cout << "here I'm in file output";
	this->_isFileOutput = isFiled;
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
string Logger::getTime()
{
    // formating time stump
	char buffer[1000];
	time_t t = time(NULL);
	struct tm* lt = localtime(&t);
	snprintf(buffer, 10000, "%02d/%02d/%02d %02d:%02d:%02d", lt->tm_mon + 1, lt->tm_mday, lt->tm_year % 100, lt->tm_hour, lt->tm_min, lt->tm_sec);
	cout << buffer;
	return buffer;
}
bool Logger::IsConsoleOutput() {
	return _isConsoleOutput;
}
bool Logger::IsFileOutput() {
	return _isFileOutput;
}
template <typename T> Logger&  operator<< (Logger& log, T const value)
{
	cout << value;
	if (log.IsConsoleOutput()) cout << value<<"["<< log.getLableType()<<"]"<< log.getTime()<<" \n";
		//addToFile("output.txt", value);//ask for this illegal call for non-static memeber
	return log;
}

Logger* Logger:: info()
{
	type = INFO;
	return InstanceLogger;
}