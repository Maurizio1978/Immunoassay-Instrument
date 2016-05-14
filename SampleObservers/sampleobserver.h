#ifndef SAMPLEOBSERVER_H
#define SAMPLEOBSERVER_H

#include <Logger/logger.h>
#include <Samples/sampleslist.h>

class SampleObserver
{
private:
    SamplesList *m_SamplesListToObserve;
public:
    SampleObserver(SamplesList *samplesListToObserve);
    ~SampleObserver();

    virtual void Update() = 0;
};


#endif // SAMPLEOBSERVER_H

