#ifndef COMMAND_DISPATCHER_DOT_H
#define COMMAND_DISPATCHER_DOT_H

#include <string>
#include "./commands/ComputationContext.h"
#include "ObjectFactory.h"
#include "./commands/SeniorCitizenCommand.h"

class CommandDispatcher
{
private:
    static ObjectFactory objectFactory;

public:
    static bool Dispatch(const std::string &archetype, ComputationContext &ctx)
    {
        std::shared_ptr<BaseComputationCommand> cmd = objectFactory.Get(archetype);
        if (cmd == nullptr)
            return false;
        if (cmd->PreExecute(ctx))
        {
            bool rs = cmd->Execute(ctx);
            cmd->PostExecute(ctx);
            return rs;
        }
        return false;
    }
};

// Initialize the ObjectFactory with your XML file path
ObjectFactory CommandDispatcher::objectFactory("/Users/midhundarvin/workplace/c++/cpp-plugin-arch/config.xml");

#endif