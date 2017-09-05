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
    void reStart();

    //获取时间间隔.单位(ms)
    double getElapsedTime();
    // 获取当前时间,格式为"YYYY-MM-DD HH:MM:SS.MMM"
    static std::string getCurrentDate();
    //获取系统时间毫秒，距离1970年1月1日0点0分0秒的毫秒数
    static long long getSystemTime();

private:
    timeb m_Start;
    timeb m_End;
};






#endif //TIMEUTIL_H
