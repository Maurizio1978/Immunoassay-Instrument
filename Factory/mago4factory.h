#ifndef MAGO4FACTORY
#define MAGO4FACTORY

#include "factory.h"
#include "Mago4/Mago4DilutionRack/mago4dilutionrack.h"
#include "Mago4/Mago4SampleRack/mago4samplerack.h"
#include "Mago4/Mago4WellRack/mago4wellrack.h"


namespace factory
{

class Mago4Factory : public Factory {
  public:
    virtual instrument::DilutionRackSP createDilutionRack()
    {
        return boost::shared_ptr<instrument::DilutionRack>(new mago4::Mago4DilutionRack);
    }

    virtual instrument::SampleRackSP createSampleRack()
    {
        return boost::shared_ptr<instrument::SampleRack>(new mago4::Mago4SampleRack);
    }

    virtual instrument::WellRackSP createWellRack()
    {
        return boost::shared_ptr<instrument::WellRack>(new mago4::Mago4WellRack);
    }
};
}   // namespace factory

#endif // MAGO4FACTORY

