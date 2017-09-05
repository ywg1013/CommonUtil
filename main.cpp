#include <QCoreApplication>
#include "timeutil.h"
#include "stringutil.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  TimeUtil time;
  time.start();
  std::string dateStr = TimeUtil::getCurrentDate();
  std::cout<< dateStr << std::endl;

  long long aa = TimeUtil::getSystemTime();
  std::cout << aa << std::endl;

  std::cout<< time.getElapsedTime() << std::endl;

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


  return a.exec();
}
