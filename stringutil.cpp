
#include "stringutil.h"

#include <limits.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>




StringUtil::StringUtil()
{
}

StringUtil::~StringUtil()
{
}

std::string StringUtil::ConcatWithChar(std::vector<long>& source, char sep)
{
    std::string result;
    std::vector<long>::iterator iter = source.begin();
    while (iter != source.end())
    {
        result += StringUtil::LLToString(*iter);
        result += sep;
        iter++;
    }
    return result;
}

std::string StringUtil::ConcatWithChar(std::set<long>& source, char sep)
{
    std::string result;
    std::set<long>::iterator iter = source.begin();
    while (iter != source.end())
    {
        result += StringUtil::LLToString(*iter);
        result += sep;
        iter++;
    }
    return result;
}

std::string StringUtil::ConcatWithChar(std::map<long, long>& source, char sep1, char sep2)
{
    std::string result;
    std::map<long, long>::iterator iter = source.begin();
    while (iter != source.end())
    {
        result += StringUtil::LLToString(iter->first);
        result += sep1;
        result += StringUtil::LLToString(iter->second);
        result += sep2;
        iter++;
    }
    return result;
}

std::string StringUtil::ConcatWithChar(std::map<int, std::string>& source, char sep1, char sep2)
{
    std::string result;
    std::map<int, std::string>::iterator iter = source.begin();
    while (iter != source.end())
    {
        result += StringUtil::IntToStr(iter->first);
        result += sep1;
        result += iter->second;
        result += sep2;
        iter++;
    }
    return result;
}

std::string StringUtil::ConcatWithChar(std::map<long long, std::string>& source, char sep1, char sep2)
{
    std::string result;
    std::map<long long, std::string>::iterator iter = source.begin();
    while (iter != source.end())
    {
        result += StringUtil::LLToString(iter->first);
        result += sep1;
        result += iter->second;
        result += sep2;
        iter++;
    }
    return result;
}

std::string StringUtil::DigitSizeToString(long long size)
{
    std::stringstream stream;
    stream.precision(1);
    stream.setf(std::ios::fixed, std::ios::floatfield);

    double dT = double(size) / (1024 * 1024) / (1024 * 1024);
    if (dT >= 1.0) // 大于1T
    {
        stream << dT << " TB";
    }
    else
    {
        double d1G = 1024 * 1024 * 1024;
        double dG = double(size) / d1G;
        if (dG >= 1.0) // 大于1G
        {
            stream << dG << " GB";
        }
        else
        {
            double d1M = 1024 * 1024;
            double dM = double(size) / d1M;
            if (dM >= 1.0) // 大于1M
            {
                stream << dM << " MB";
            }
            else
            {
                double d1K = 1024;
                double dK = double(size) / d1K;
                if (dK >= 1.0) // 大于1K
                {
                    stream << dK << " KB";
                }
                else // 小于1K
                {
                    stream << size << " B";
                }
            }
        }
    }

    return stream.str();
}

std::string StringUtil::TimeToString(long long  seconds)
{

    std::stringstream stream;
    long long  secs = seconds;
    if (secs > 0)
    {
        long long  tv = secs / 86400; // 1天 == 86400秒
        if (tv != 0)
        {
            stream << tv << "d ";
            secs %= 86400;
        }
        tv = secs / 3600; // 1小时 == 3600秒
        if (tv != 0)
        {
            stream << tv << "h ";
            secs %= 3600;
        }
        tv = secs / 60; // 1分钟 == 60秒
        if (tv != 0)
        {
            stream << tv << "m ";
            secs %= 60;
        }
        if(secs != 0)
        {
            stream << secs << "s";
        }
    }
    else if (secs == 0)
    {
        stream << secs << "s";
    }

    return stream.str();
}

long long StringUtil::TimeStringToSeconds(const std::string &timeStr)
{
    long long  seconds = 0;
    // remove all the spaces
    std::string time;
    for (size_t i = 0; i < timeStr.size(); i++)
    {
        if (timeStr[i] != ' ')
        {
            time.push_back(timeStr[i]);
        }
    }
    if (!time.empty())
    {
        // day
        size_t pos = time.find_first_of("d");
        if (pos != std::string::npos)
        {
            std::string str = time.substr(0, pos);
            seconds += atoi(str.c_str()) * 86400;
            if (pos+1 < time.size())
            {
                time = time.substr(pos+1);
            }
        }
        // hour
        pos = time.find_first_of("h");
        if (pos != std::string::npos)
        {
            std::string str = time.substr(0, pos);
            seconds += atoi(str.c_str()) * 3600;
            if (pos+1 < time.size())
            {
                time = time.substr(pos+1);
            }
        }
        // minute
        pos = time.find_first_of("m");
        if (pos != std::string::npos)
        {
            std::string str = time.substr(0, pos);
            seconds += atoi(str.c_str()) * 60;
            if (pos+1 < time.size())
            {
                time = time.substr(pos+1);
            }
        }
        // second
        pos = time.find_first_of("s");
        if (pos != std::string::npos)
        {
            std::string str = time.substr(0, pos);
            seconds += atoi(str.c_str());
            if (pos+1 < time.size())
            {
                time = time.substr(pos+1);
            }
        }
    }
    return seconds;
}



std::string StringUtil::Replace_Char(const std::string & str, const char old_value, const char new_value)
{
	std::stringstream result;

	for (size_t i = 0; i < str.size(); i++ )
	{
		if (str.at(i) == old_value)
		{
			result << new_value;
		}
		else
			result << str.at(i);
	}

	return result.str();
}


std::string StringUtil::Replace_Str(std::string & s1, const std::string & s2, const std::string & s3)
{
    std::string::size_type pos = 0;
    std::string::size_type a = s2.size();
    std::string::size_type b = s3.size();
    while((pos = s1.find(s2, pos)) != std::string::npos)
    {
        s1.replace(pos, a, s3);
        pos += b;
    }
    return s1;
}

std::string StringUtil::Trim(std::string str)
{
	//去掉前面的空格
	size_t pos_value_front_space = str.find_first_not_of(" \t");
	if (pos_value_front_space != std::string::npos)
	{
		str.erase(0, pos_value_front_space);
	}
	//去掉后面的空格
	size_t pos_value_end_space = str.find_last_not_of(" \t");
	if (pos_value_end_space != std::string::npos)
	{
		str.erase(pos_value_end_space + 1);
	}
	return str;
}




