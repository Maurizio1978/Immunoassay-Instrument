#ifndef HOLDER_H
#define HOLDER_H

#include <vector>
#include <InstrumentDefinition/bay.h>

class Holder
{
public:
    Holder();
    ~Holder();

private:
    std::vector<Bay> m_Bays;
};

#endif // HOLDER_H
