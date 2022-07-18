#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;
enum Typelog {
	DEBUG,
	INFO,
	WARN,
	ERROR
};

class Logger
{
	static stringstream data;
private:
	static Logger* InstanceLogger;
	string msglevel = "";
	Logger(){}
	static bool isCommanded ;
	static Typelog type;

protected:
	
public:
  void setLoggerType(Typelog type);
  static Logger* GetInstance();
  void setOutputFormat(bool isCommanded);
  bool getOutputFormat();
  bool addToFile(string FileName, string Value);


	template <typename T>
	friend Logger& operator <<(Logger& log, T const& value)// unable to write in cpp file
	{
		if (isCommanded) cout << value;
		//addToFile("output.txt", value);//ask for this illegal call for non-static memeber
		return log;
	}
	




	
};

