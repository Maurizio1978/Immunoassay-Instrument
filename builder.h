#ifndef BUILDER_H
#define BUILDER_H

#include <InstrumentDefinition/instrument.h>

class Builder
{
public:
    virtual ~Builder() {}

    Instrument* GetInstrument()
    {
        return m_Instrument;
    }

    void BuildNewInstrument()
    {
        m_Instrument = new Instrument();
    }

    virtual void BuildPlateRack() = 0;
    virtual void BuildSampleRack() = 0;
    virtual void BuildDilutionRack() = 0;
    virtual void BuildReagentRack() = 0;

protected:
    Instrument *m_Instrument;
};

class Mago4Builder : public Builder
{
public:
    virtual void BuildPlateRack();

    virtual void BuildSampleRack();

    virtual void BuildDilutionRack();

    virtual void BuildReagentRack();

    ~Mago4Builder()
    {
        if (m_Instrument)
            delete m_Instrument;
    }

private:
    static const int NUM_OF_PLATE_HOLDERS = 4;
    static const int NUM_OF_SAMPLE_HOLDERS = 1;
};

class Mago4sBuilder : public Builder
{
public:
    virtual void BuildPlateRack();

    virtual void BuildSampleRack();

    virtual void BuildDilutionRack();

    virtual void BuildReagentRack();

    ~Mago4sBuilder()
    {
        if (m_Instrument)
            delete m_Instrument;
    }

private:
    static const int NUM_OF_PLATE_HOLDERS = 4;
    static const int NUM_OF_SAMPLE_HOLDERS = 2;
};

#endif
