#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <sstream>
#include <tinythread.h>

using namespace std;

class logger
{
public:
    static void Info(const string& strMessage);
    static void Info(const string& strFormat, const string& value);
    static void Info(const string& strFormat, const int& value);

    static void Error(const string& strMessage);
    static void Error(const string& strFormat, const string& value);
    static void Error(const string& strFormat, const int& value);

private:
    static logger& GetInstance();
    logger& operator << (const string& strMessage);

    logger(logger const&){}
    logger& operator=(logger const&){}

    logger();
    ~logger();

    static stringstream m_FileName;
    static ofstream m_FileStream;
    static tthread::mutex logger_lock;
};

#endif // LOGGER_H
