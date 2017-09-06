#include "timeutil.h"
#include <chrono>
using namespace std::chrono;

TimeUtil::TimeUtil()
{

}

void TimeUtil::start()
{
   m_Start = steady_clock::now();
}

void TimeUtil::reStart()
{
   start();
}

long long TimeUtil::getElapsedTime()
{
   m_End = steady_clock::now();
   steady_clock::duration time_span = m_End - m_Start;
//   double nseconds = double(time_span.count()) * steady_clock::period::num / steady_clock::period::den;

   return time_span.count();

}

std::string TimeUtil::getCurrentDate()
{
  system_clock::time_point now = system_clock::now();
  time_t tt = system_clock::to_time_t(now);
  struct tm * timeinfo = localtime(&tt);

  char secondBuffer [30];
  strftime(secondBuffer, 30, "%Y-%m-%d %H:%M:%S", timeinfo);
  return std::string(secondBuffer);

}

long long TimeUtil::getSystemTimeMilli()
{
   return getSystemTimeMicro()/1000;
}

long long TimeUtil::getSystemTimeMicro()
{
  return getSystemTimeNano()/1000;
}

long long TimeUtil::getSystemTimeNano()
{
  system_clock::time_point now = system_clock::now();
  nanoseconds elapsed = now.time_since_epoch();
  return elapsed.count();
}
