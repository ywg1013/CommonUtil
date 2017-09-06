#include "timeutil.h"

TimeUtil::TimeUtil()
{

}

void TimeUtil::start()
{
   ftime(&m_Start);
}

void TimeUtil::reStart()
{
   start();
}

double TimeUtil::getElapsedTime()
{
   ftime(&m_End);
   return difftime(m_End.time,m_Start.time)*1000+m_End.millitm-m_Start.millitm;

}

std::string TimeUtil::getCurrentDate()
{
  timeb tb;
  ftime(&tb);
  struct tm * timeinfo;
  timeinfo = localtime(&tb.time);

  char secondBuffer [30];
  strftime(secondBuffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
  char millitmBuffer [34];
  sprintf(millitmBuffer,"%s.%03d",secondBuffer,tb.millitm);
  return std::string(millitmBuffer);

}

long long TimeUtil::getSystemTime()
{
   timeb tb;
   ftime(&tb);
   return tb.time*1000+tb.millitm;
}
