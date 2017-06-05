#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "SampleRack/samplerack.h"
#include "DilutionRack/dilutionrack.h"
#include "WellRack/wellrack.h"

namespace Instrument
{
//typedef boost::shared_ptr<dilutionRack::DilutionRack> DilutionRackSP;
//typedef boost::shared_ptr<sampleRack::SampleRack> SampleRackSP;
//typedef boost::shared_ptr<wellRack::WellRack> WellRackSP;

class Instrument
{
public:
    Instrument(const SampleRack& iSampleRack, const DilutionRack& iDilutionRack, const WellRack& iWellRack);
private:
    SampleRack& _sampleRack;
    DilutionRack& _dilutionRack;
    WellRack& _wellRack;

};  // class instrument
}   // namespace Instrument

#endif // INSTRUMENT_H
