#ifndef COMPUTATION_COMMAND_DOT_H
#define COMPUTATION_COMMAND_DOT_H
#include "./ComputationContext.h"

class BaseComputationCommand
{
public:
    virtual bool PreExecute(ComputationContext &ctx)
    {
        return true;
    };
    virtual bool Execute(ComputationContext &ctx)
    {
        return true;
    };
    virtual bool PostExecute(ComputationContext &ctx)
    {
        return true;
    };
    virtual ~BaseComputationCommand() = default; // Define a virtual destructor if needed
    virtual std::shared_ptr<BaseComputationCommand> Clone() const = 0;
};
#endif