#include <iostream>
#include "Logger.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
  Logger* log = Logger::GetInstance();
  log->setOutputFormat(true);//to consoule
  log->setLoggerType(INFO);
  *log<< "---hi it's sabah "<<"tett";




 

}

