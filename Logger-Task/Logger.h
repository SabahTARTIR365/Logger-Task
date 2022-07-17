#pragma once
#include <ostream>
#include <iostream>
using namespace std;
class Logger
{
private:
	static Logger* InstanceLogger;
	static stringstream data;
	Logger(){}
	
protected:
	
public:
	
	static Logger* GetInstance();
/*	template <typename T>
	friend Logger& operator <<(Logger& log, T const& value) {
		cout << value;
		log.data << value;
		return log;
	}

	friend void operator<<(Logger& d, string s)
	{
		// cout assigned to another object mycout
		
		cout << "Value of s= are \n";
		
	}

	/*friend void operator << (ostream& out, const Logger& c)
	{   
		stringstream d = "";
		//out << InstanceLogger->something;
		//out << c.something << endl;
		out << "hi";

		//return out;
	}*/
	
};

