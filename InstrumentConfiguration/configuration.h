#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <QFile>
#include <QtXml>

class Configuration
{
public:
    Configuration();
    ~Configuration();

    void ReadParameters();

private:
    QString _InstrumentVersion;
};

#endif // CONFIGURATION_H
