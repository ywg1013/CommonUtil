/**
 * @file TimeUtil.h
 * @brief 时间打印类.
 */

#ifndef TIMEUTIL_H
#define TIMEUTIL_H
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <sys/timeb.h>



class  TimeUtil
{
public:
    TimeUtil();
    void start();
    void end();

    long long getUseTime();

    /**
     * 获取当前时间,格式为"YYYY-MM-DD HH:MM:SS.MMM"
     */
    static std::string getCurrentDate();

    static long long getSystemTime();

private:
    timeb m_Start;
    timeb m_End;
};






#endif //TIMEUTIL_H
