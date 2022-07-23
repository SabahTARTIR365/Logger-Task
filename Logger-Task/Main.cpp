#include <iostream>
#include "Logger.h"
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
  Logger* log = Logger::GetInstance();
 log->setConsoleFormatOutput(true);//to consoule
  log->setLoggerType(INFO);
  *log << "hi it' s sabah";
 *log->info()<< "hi it' s sabah";




 

}

