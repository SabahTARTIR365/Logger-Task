#include "pch.h"
#include "../Logger-Task/Logger.h"
#include "../Logger-Task/Logger.cpp"
#include "cppUnitTest.h"
#include <iostream>
#include <math.h> 
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(LoggerTest, fileIsOpenTest) {
    Logger* log = Logger::GetInstance();
    string file =  "output1.txt";
  ofstream fout(file, ios::app);
    log->addToFile(file, "unittest - message");
    bool FileExists = std::ofstream(file).good();
    EXPECT_TRUE(FileExists);

}

TEST(LoggerTest, notNullSingelton) {
    Logger* log = Logger::GetInstance();

    EXPECT_TRUE(log != nullptr);

}







/**log->setConsoleFormatOutput(true);//to consoule

log->setLoggerLevel(ERROR);
*log->error() << "ERROR1 COULDhappen heree ";
*log->error() << "ERROR 2COULDhappen heree ";
*log->error() << "ERROR 3COULDhappen heree ";

string file = "output.txt";
ifstream fin(file, ios::in);
string line;
//string a = '[ERROR]';

 int numWords = 0;
 while (getline(fin, line))
 {

     stringstream lineStream(line);
     while (getline(lineStream, line, '['))
     {
         numWords++;
     }
 }
fin.close();
 // EXPECT_EQ(3, numWords);
*/