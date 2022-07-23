#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
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
	static Typelog type;

public:
  void setLoggerLevel(Typelog type);
  static Logger* GetInstance();
  void setConsoleFormatOutput(bool isConsoled);
  void setFileFormatOutput(bool isFiled);
  static bool  IsConsoleOutput();
  static bool IsFileOutput();
  string getTime();
  bool addToFile(string FileName, string Value);
  Logger* info();
  Logger* warn();
  Logger* depug();
  Logger* error();
  Logger* silent();

template <typename T> friend Logger& operator <<(Logger& log, T const value);// unable to write in cpp file
	/*{
		if (isCommanded) cout << value;//<<"["<< getLableType()<<"] \n";
		//addToFile("output.txt", value);//ask for this illegal call for non-static memeber
		return log;
	}*/
	




	
};

