#include "timeutil.h"
#include "stringutil.h"
#include <iterator>
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[])
{

  TimeUtil time;
  time.start();
  std::string dateStr = TimeUtil::getCurrentDate();
  std::cout<< dateStr << std::endl;

  time.reStart();
  std::cout << TimeUtil::getSystemTimeMilli() << std::endl;
  std::cout<< time.getElapsedTime() << std::endl;

  std::cout<< TimeUtil::getSystemTimeMilli() << "  milli second"<<  std::endl;

  std::cout<< TimeUtil::getSystemTimeMicro()<< " micro second"<<  std::endl;

  std::cout<< TimeUtil::getSystemTimeNano() << "  nano second" <<std::endl;

  //  /////////////////////////////////////////////////////////////////

  std::cout<<" /////////////////////////////////////////////////////////" << std::endl;

  std::cout << StringUtil::LongToStr(1234) << std::endl;
  std::cout << StringUtil::FloatToStr(345.256,2) << std::endl;
  std::cout << StringUtil::StrToDouble("32.123") << std::endl;
  std::cout << StringUtil::StrToInt("36.55") << std::endl;
  std::cout << StringUtil::FloatToStr(4467.563567608)<< std::endl;
  std::cout << StringUtil::FloatToStr(4467.563567608,9)<< std::endl;
  std::cout << "   hjfd hjfkj jfkd "<< std::endl;
  std::cout << StringUtil::Trim("   hjfd hjfkj jfkd ")<< std::endl;
  std::cout << StringUtil::FloatToStr(4467.563567608,9)<< std::endl;
  std::cout << StringUtil::DigitSizeToString(75475848458)<< std::endl;
  std::cout << StringUtil::CompareEqual(3.12345678777,3.12345678776) << std::endl;
  std::cout << StringUtil::CompareEqual(3.12345678777,3.12345678777) << std::endl;

  std::string str1 = "345#78#23#89";
  std::string str2 = "jfkd&&jfkdkslf&&334&&hhh";
  std::vector<std::string> str1vect,str2vect;
  SplitByString(str2,"&&", str2vect);
  SplitByChar(str1,'#', str1vect);

  std::copy(str1vect.begin(), str1vect.end(), std::ostream_iterator<std::string> (std::cout, " "));
  std::cout << std::endl;
  std::copy(str2vect.begin(), str2vect.end(), std::ostream_iterator<std::string> (std::cout, " "));
  std::cout << std::endl;
}
