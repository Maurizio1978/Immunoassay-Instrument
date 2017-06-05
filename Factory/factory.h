#ifndef FACTORY_H
#define FACTORY_H

#include "Instrument/instrument.h"

namespace factory
{

class Factory
{
public:
    virtual Instrument::DilutionRack createDilutionRack() = 0;
    virtual Instrument::SampleRack createSampleRack() = 0;
    virtual Instrument::WellRack createWellRack() = 0;
};

}       // namespace factory
#endif  // FACTORY_H
