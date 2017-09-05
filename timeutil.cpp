#include "timeutil.h"
#include <Windows.h>

TimeUtil::TimeUtil()
{

}

void TimeUtil::start()
{
   ftime(&m_Start);
}

void TimeUtil::end()
{
   ftime(&m_End);

}

long long TimeUtil::getUseTime()
{
   return difftime(m_End.time,m_Start.time);
}

std::string TimeUtil::getCurrentDate()
{
 // int milli = int(getSystemTime()) / 1000;

  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
  return std::string(buffer);
//  char currentTime[84] = "";
//  sprintf(currentTime, "%s:%d", buffer, milli);
//  return std::string(currentTime);
}

long long TimeUtil::getSystemTime()
{
   timeb tb;
   ftime(&tb);
   printf(".%03d\n",tb.millitm);
   return 1111;
}
