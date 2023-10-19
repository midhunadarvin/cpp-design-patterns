#include "SeniorCitizenCommand.h"

extern "C" SeniorCitizenCommand *createSeniorCitizenCommand()
{
    return new SeniorCitizenCommand;
}

extern "C" void destroySeniorCitizenCommand(SeniorCitizenCommand *c)
{
    delete c;
}
