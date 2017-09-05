#include <QCoreApplication>
#include "timeutil.h"
#include "stringutil.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  std::string dateStr = TimeUtil::getCurrentDate();
  long long aa = TimeUtil::getSystemTime();
  std::cout<< dateStr << std::endl;
//  return a.exec();
}
