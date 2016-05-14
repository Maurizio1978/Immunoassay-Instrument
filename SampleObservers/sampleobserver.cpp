#include <SampleObservers/sampleobserver.h>

SampleObserver::SampleObserver(SamplesList *samplesListToObserve)
{
    m_SamplesListToObserve = samplesListToObserve;
    m_SamplesListToObserve->AttachObserver(this);
}

SampleObserver::~SampleObserver()
{

}

void SamplesList::Notify()
{
    //std::vector<class m_SampleObservers *>::iterator it;

    for (int i = 0; i < this->m_SampleObservers.size(); ++i)
        this->m_SampleObservers[i]->Update();
    //for (it = m_SampleObservers.begin(); it != m_SampleObservers.end(); it++)

}

