#include "./OrdinaryCitizenCommand.h"

extern "C" OrdinaryCitizenCommand *createOrdinaryCitizenCommand()
{
    return new OrdinaryCitizenCommand;
}

extern "C" void destroyOrdinaryCitizenCommand(OrdinaryCitizenCommand *c)
{
    delete c;
}

