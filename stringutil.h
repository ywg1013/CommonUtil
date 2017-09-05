
#ifndef STRINGUTIL_H
#define STRINGUTIL_H


#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <string.h>
#include <cfloat>
#include <cmath>



class  StringUtil
{
public:

    StringUtil();
    ~StringUtil();


    /**
     * @brief string类型变量转换为int类型变量
     * @param[in] s string类型变量
     * @return int型变量
     *
     */
    static int StrToInt(const std::string& s)
    {
        return std::stoi(s.c_str());
    }

    /**
     * @brief string类型变量转换为float类型变量
     * @param[in] s string类型变量
     * @return float型变量
     *
     */
    static float StrToFloat(const std::string& str)
    {
        return std::stof(str);
    }

    /**
     * @brief string类型变量转换为float类型变量
     * @param[in] s string类型变量
     * @return double型变量
     *
     */
    static double StrToDouble(const std::string& str)
    {
        return std::stod(str);
    }


    /**
     * @brief string类型变量转换为long long类型变量
     * @param[in] s string类型变量
     * @return long long型变量
     *
     */
    static long long StrToLL(const std::string& str)
    {     
         return std::stoll(str);
    }

    /**
     * @brief int类型变量转换为string类型变量
     * @param[in] value int类型变量
     * @return string型变量
     *
     */
    static std::string LongToStr(long value)
    {
         return std::to_string(value);
    }

    /**
     * @brief long long类型变量转换为string类型变量
     * @param[in] value long long类型变量
     * @return string型变量
     *
     */
    static std::string LLToString(long long value)
    {
        char buff[64];
        std::sprintf(buff, "%lld", value);
        return std::string(buff);
    }


    /**
     * @brief float类型变量转换为string类型变量
     * @param[in] value float类型变量
     * @return string型变量
     *
     */
    static std::string FloatToStr(double value)
    {
      return std::to_string(value);
    }

    /**
     * @brief float类型变量转换为string类型变量
     * @param[in] value float类型变量
     * @return string型变量
     *
     */
    static std::string FloatToStr(double value,int digits)
    {
        char buff[64];
        std::stringstream ss;
        ss << "%0." << digits << "f";
        std::sprintf(buff, ss.str().c_str(), value);
        return buff;
    }

    /**
     * @brief 比较两个float类型是否相等
     * @param[in] value float类型变量
     * @return 相等true 否则返回false
     */
    static bool CompareEqual(float value1,float value2)
    {
        if(fabs(value1-value2) <  FLT_EPSILON)
                return true;
    	else
    		return false;
    }

    /**
     * @brief 比较两个double类型是否相等
     * @param[in] value double类型变量
     * @return 相等true 否则返回false
     */
    static bool CompareEqual(double value1,double value2)
    {
        if(fabs(value1-value2) < DBL_EPSILON)
    		return true;
    	else
    		return false;
    }

	/**
	 * @brief 判断是否为空值
	 * @param[in] value 点
	 * @return true 空值(FLT_MIN), false 有效值(非空)
	 */
    static bool IsEmptyValue(float value)
    {
    	if(fabs(value-FLT_MIN) < FLT_EPSILON)
    		return true;
    	else
    		return false;
    }


    /**
     * @brief 将数字的容量大小装换为格式化的字符串
     *
     * 如：1=1KB  1024=1MB
     *
     * @param[in] size 文件大小
     */
    static std::string DigitSizeToString(long long size);



    /**
     * @brief 将经过的时间（以秒计算），转换为方便人类识别的字符串
     * @param[in] seconds 经过的时间，单位为秒
     * @return 方便识别的字符串
     */
    static std::string TimeToString(long long seconds);

    /**
     * @brief 将友好格式的经过时间字符串，转换为秒
     * @param[in] timeStr 友好格式的经过时间字符串
     * @return 经过的时间（以秒计算）
     */
    static long long  TimeStringToSeconds(const std::string &timeStr);





    /**
     * @brief 根据分割符合并字符串
     * @return 合并后的字符串
     */
    static std::string ConcatWithChar(std::vector<long>& source, char sep);
    static std::string ConcatWithChar(std::set<long>& source, char sep);
    static std::string ConcatWithChar(std::map<long, long>& source, char sep1, char sep2);
    static std::string ConcatWithChar(std::map<int, std::string>& source, char sep1, char sep2);
    static std::string ConcatWithChar(std::map<long long, std::string>& source, char sep1, char sep2);

    /**
     * @brief 根据传入的字符替换字符串中的所有匹配字符
     */
    static std::string Replace_Char(const std::string & str, const char old_value, const char new_value);

    /**
     * @brief 根据传入的字符替换字符串中的所有匹配字符串
     */
    static std::string Replace_Str(std::string & s1, const std::string & s2, const std::string & s3);

    /**
     * @brief 去掉给定字符串前后的空格
     * @param[in] str 操作串
     *
     * @return 去掉空格后的字符串
     */
    static std::string Trim(std::string str);
private:


    /**
     * @return Number of matching items.
     */
    static int ListFiles(const std::string& path, const std::string& filter, std::vector<std::string>& file);

};



template <class C>
void SplitByChar(const std::string& s, char sep, C& result, bool allowEmpty = true)
{
    size_t len = s.size();
    std::string line;
    for (size_t i = 0; i < len; i++)
    {
        char c = s[i];
        if (c == sep)
        {
            if (!allowEmpty)
            {
                if (!line.empty())
                    result.push_back(line);
            } else
            {
                result.push_back(line);
            }
            line.clear();
        } else
        {
            line.push_back(c);
        }
    }
    if (!line.empty())
    {
        result.push_back(line);
    }
}

template <class C>
int SplitByString(const std::string& strsplit, const std::string splitflag, C& splits)
{
    const char *str = strsplit.c_str();
    size_t size = strsplit.size() + 1;
    char *str_tmp = reinterpret_cast<char*> (malloc(size));
    memset(str_tmp, '\0', size);
    strcpy(str_tmp, str);
    const char *split = splitflag.c_str();
    char *file = NULL;
    if (strsplit.find(splitflag) != std::string::npos)
    {
        file = strtok(str_tmp, split);
        while (file != NULL)
        {
            splits.push_back(file);
            file = strtok(NULL, split);
        }
    }
    else
    {
        splits.push_back(strsplit);
    }
    free(str_tmp);
    return static_cast<int> (splits.size());
}


#endif //STRINGUTIL_H
