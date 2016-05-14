#ifndef READER
#define READER
#include <tinythread.h>
tthread::condition_variable initialization_con;


class Reader
{
public:
    void Intialize();
};

#endif // READER

