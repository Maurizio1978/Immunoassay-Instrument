#ifndef RACK_H
#define RACK_H

#include <InstrumentDefinition/holder.h>

class Rack
{
public:
    Rack();
    ~Rack();

private:
    std::vector<Holder> m_Holders;
};

#endif // RACK_H
