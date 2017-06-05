#ifndef MAGO4SFACTORY
#define MAGO4SFACTORY

#include "factory.h"
#include "Mago4s/Mago4sDilutionRack/mago4sdilutionrack.h"
#include "Mago4s/Mago4sSampleRack/mago4ssamplerack.h"
#include "Mago4s/Mago4sWellRack/mago4swellrack.h"

namespace factory
{
class Mago4sFactory : public Factory {
  public:
    virtual instrument::DilutionRackSP createDilutionRack()
    {
        return boost::shared_ptr<instrument::DilutionRack>(new mago4s::Mago4sDilutionRack);
    }

    virtual instrument::SampleRackSP createSampleRack()
    {
        return boost::shared_ptr<instrument::SampleRack>(new mago4s::Mago4sSampleRack);
    }

    virtual instrument::WellRackSP createWellRack()
    {
        return boost::shared_ptr<instrument::WellRack>(new mago4s::Mago4sWellRack);
    }

};
}   // namespace factory

#endif // MAGO4SFACTORY

