#ifndef INSTRUMENTCREATOR_H
#define INSTRUMENTCREATOR_H

#include <builder.h>
#include <Exceptions/exceptions.h>
#include <SampleObservers/sampleobserver.h>
#include <QFile>
#include <QtXml>

class InstrumentCreator : public SampleObserver
{
public:
    InstrumentCreator(Builder *instrumentBuilder, SamplesList *samplesListToObserve) : SampleObserver(samplesListToObserve)
    {
        m_InstrumentBuilder = instrumentBuilder;
    }

    ~InstrumentCreator();

    Instrument* GetInstrument();

    void Update();

    static QString m_InstrumentVersion;
    static void ReadXML();
    void CreateInstrument();

private:
    Builder *m_InstrumentBuilder;
};

#endif // INSTRUMENTCREATOR_H
