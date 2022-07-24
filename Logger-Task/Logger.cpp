#include "Logger.h"
#include <fstream>
#include <unordered_map>
 Logger* Logger::InstanceLogger = 0;
 bool Logger::_isConsoleOutput =true;
 bool Logger::_isFileOutput = true;
 Typelog  Logger::messageType = DEBUG;
 Typelog Logger::Level= DEBUG;
 unordered_map <Typelog, string> Logger::Label;

 template Logger& operator << (Logger& log, int const value);
 template Logger& operator << (Logger& log, double const value);
 template Logger& operator << (Logger& log,  const char * const value);


 void Logger::setMessageType(Typelog messageType)
 {
	 Logger::messageType = messageType;
 }
 Typelog Logger::getMessageType() {

	 return Logger::messageType;
 }
 string Logger::getMessageLable()
 {  
	// InstanceLogger->setMessageLabel();
	 return Logger::Label[messageType];
 }

 void Logger::setLoggerLevel(Typelog type)
 {
	 this->Level = type;
 }

 Logger* Logger::GetInstance()
{

	 return (!InstanceLogger) ? 
		 InstanceLogger = new Logger()  : 
		 InstanceLogger;
}

void Logger::setConsoleFormatOutput(bool  isConsoled)
{ 
	this->_isConsoleOutput = isConsoled;
}

void Logger::setFileFormatOutput(bool isFiled)
{
	this->_isFileOutput = isFiled;
}

template <typename T> void Logger::addToFile(string FileName, T Value)
{  
	
	ofstream fout(FileName, ios::app);
	if (Logger::Level <= Logger::getMessageType()) {
		if (fout.is_open()) {
			fout << Logger::getMessageLable(); 
			fout << Logger::getTime() << Value << "\n";
			fout.close();
		}
		else cout << "Unable to open file";
	}
}

string Logger::getTime()
{
    // formating time stump
	char buffer[1000];
	time_t t = time(NULL);
	struct tm* lt = localtime(&t);
	snprintf(buffer, 10000, "%02d/%02d/%02d %02d:%02d:%02d ", lt->tm_mon + 1, lt->tm_mday, lt->tm_year % 100, lt->tm_hour, lt->tm_min, lt->tm_sec);
	//cout << buffer;
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
	if (log.IsConsoleOutput())
	{      
		if (Logger::Level <= log.getMessageType())
		{
			cout << log.getMessageLable(); 
			cout << log.getTime() << value << " \n";
		}
	}
	if (log.IsFileOutput()) {  log.addToFile("output.txt", value); }
	return log;
}

Logger* Logger::depug()
{  
	Logger::Label[DEBUG] = "[DEBUG] ";
	Logger::setMessageType(DEBUG);
	return InstanceLogger;
}
Logger* Logger:: info()
{
	Logger::Label[INFO] = "[INFO] ";
	Logger::setMessageType(INFO);
	return InstanceLogger;
}
Logger* Logger::warn()
{
	Logger::Label[WARN] = "[WARN] ";
	Logger::setMessageType(WARN);
	return InstanceLogger;
}
Logger* Logger::error()
{
	Logger::Label[ERROR] = "[ERROR] ";
	Logger::setMessageType(ERROR);
	return InstanceLogger;
}
Logger* Logger::silent()
{
	Logger::Label[SILENT] = "[SILENT] ";
	Logger::setMessageType(SILENT); 
	return InstanceLogger;
}