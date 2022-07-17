#include <iostream>
#include "Logger.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
  Logger* gg = Logger::GetInstance();
 // cout << gg;
//  operator << (*gg, "hi");

  //*gg << "hi";


    //cout<< gg << "hi" ;

}

