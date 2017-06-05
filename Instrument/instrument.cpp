#include "instrument.h"

namespace Instrument
{

Instrument::Instrument(const SampleRack& iSampleRack, const DilutionRack& iDilutionRack,
                       const WellRack& iWellRack) :
    _sampleRack(iSampleRack),
    _dilutionRack(iDilutionRack),
    _wellRack(iWellRack)
{}

}   // namespace instrument
