#include <Samples/sampleslist.h>

SamplesList::SamplesList()
{

}

SamplesList::~SamplesList()
{

}

void SamplesList::AddSample(Sample sample)
{
    m_SampleList_mutex.lock();
    m_Samples.push_back(sample);
    m_SampleList_mutex.unlock();

    Notify();
}

void SamplesList::AttachObserver(class SampleObserver *sampleObserver)
{
   m_SampleObservers.push_back(sampleObserver);
}


