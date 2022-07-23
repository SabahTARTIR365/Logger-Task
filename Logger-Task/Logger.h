#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;
enum Typelog {
	DEBUG,
	INFO,
	WARN,
	ERROR,
	SILENT	
};
class Logger
{
	static stringstream data;
private:
	static Logger* InstanceLogger;
	string msglevel = "";
	Logger(){}
	static bool _isConsoleOutput ;
	static bool _isFileOutput ;
	static Typelog Level;
	static Typelog messageType;


public:
  void setLoggerLevel(Typelog type);
  static Logger* GetInstance();
  void setConsoleFormatOutput(bool isConsoled);
  void setFileFormatOutput(bool isFiled);
  void setMessageType(Typelog messageType);
  Typelog getMessageType();
  static bool  IsConsoleOutput();
  static bool IsFileOutput();
  static string getTime();
  template <typename T> void addToFile(string FileName,  T Value);
  static string getMessageLable();
  Logger* info();
  Logger* warn();
  Logger* depug();
  Logger* error();
  Logger* silent();
template <typename T> friend Logger& operator <<(Logger& log, T const value);

	




	
};

