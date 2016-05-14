#ifndef SAMPLESLIST_H
#define SAMPLESLIST_H

#include <string>
#include <list>
#include <vector>
#include <ctime>
#include <tinythread.h>

class Sample
{
private:
    std::string m_Name;
    std::string m_Barcode;
    tm *m_BirthDate;
public:
    Sample(std::string name, std::string barcode, tm *birthDate) : m_Name(name),
                                                                   m_Barcode(barcode),
                                                                   m_BirthDate(birthDate)
    {
    }
};

class SamplesList
{
private:
    tthread::mutex m_SampleList_mutex;
    std::list<Sample> m_Samples;

    std::vector<class SampleObserver *> m_SampleObservers;
public:
    SamplesList();
    ~SamplesList();

    void AttachObserver(class SampleObserver *sampleObserver);
    void AddSample(Sample sample);
    void Notify();
};

#endif // SAMPLESLIST_H
