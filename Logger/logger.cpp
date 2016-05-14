#include <Logger/logger.h>
#include <time.h>
#include <QFileDialog>
#include <tinythread.h>

stringstream logger::m_FileName;
ofstream logger::m_FileStream;
tthread::mutex logger::logger_lock;

logger& logger::GetInstance()
{
    static logger m_PtrInstance;

    time_t currTime;
    time(&currTime);
    struct tm *currTm = localtime(&currTime);

    if (!m_FileStream.is_open())
    {
        std::string currentDirectory = QDir::currentPath().toStdString();

        m_FileName << currentDirectory << "/log/" << (1900 + currTm->tm_year) << "_" <<
                      currTm->tm_mon << "_" << currTm->tm_mday << "_" <<
                      currTm->tm_hour << "_" << currTm->tm_min << ".log";

        m_FileStream.open(m_FileName.str(), std::ofstream::out | std::ofstream::app);
    }

    return m_PtrInstance;
}

logger& logger::operator << (const string& strMessage)
{
    time_t currTime;
    time(&currTime);
    struct tm *currTm = localtime(&currTime);

    logger_lock.lock();
    m_FileStream << "[" << currTm->tm_hour << ":" << currTm->tm_min << ":" << currTm->tm_sec << "] ---> " << strMessage << std::endl;
    logger_lock.unlock();

    return *this;
}

void logger::Info(const string& value)
{
    GetInstance().operator <<("[Info] " + value);
}

void logger::Info(const string& strFormat, const string& value)
{
    char buffer[256];
    sprintf(buffer, strFormat.c_str(), value.c_str());

    string message = buffer;
    message = "[Info] " + message;
    GetInstance().operator <<(message);
}

void logger::Info(const string& strFormat, const int& value)
{
    char buffer[256];
    sprintf(buffer, strFormat.c_str(), value);

    string message = buffer;
    message = "[Info] " + message;
    GetInstance().operator <<(message);
}

void logger::Error(const string& value)
{
    GetInstance().operator <<("[Error]" + value);
}

void logger::Error(const string& strFormat, const string& value)
{
    char buffer[256];
    sprintf(buffer, strFormat.c_str(), value);

    string message = buffer;
    message = "[Error]" + message;
    GetInstance().operator <<(message);
}

logger::logger()
{

}

logger::~logger()
{
    m_FileStream.close();
}

