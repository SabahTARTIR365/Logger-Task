#include <iostream>
#include "Logger.h"
#include <iomanip>
#include <ctime>
using namespace std;

int main()
{
   // std::cout << "Hello World!\n";
  Logger* log = Logger::GetInstance();
 log->setConsoleFormatOutput(true);//to consoule
 log->setFileFormatOutput(true);
 log->setLoggerLevel(DEBUG);

 *log->error() << "ERROR COULDhappen heree ";
 *log->warn() << "WARNING message";
 *log->info() << "Information message";
 *log->depug() << "we have some depaging un realistic";
 



 

}

