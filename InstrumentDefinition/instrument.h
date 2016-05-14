#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <InstrumentDefinition/platerack.h>
#include <InstrumentDefinition/samplerack.h>
#include <InstrumentDefinition/dilutionrack.h>
#include <InstrumentDefinition/reagentrack.h>

class Instrument
{
public:
    Instrument();
    ~Instrument();

    Platerack m_PlateRack;
    Samplerack m_SampleRack;
    Reagentrack m_ReagentRack;
    Dilutionrack m_DilutionRack;
};

#endif // INSTRUMENT_H
