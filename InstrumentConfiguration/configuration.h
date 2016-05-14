#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <QFile>
#include <QtXml>

class Configuration
{
public:
    QString m_InstrumentVersion;
    Configuration();
    ~Configuration();
};

#endif // CONFIGURATION_H
