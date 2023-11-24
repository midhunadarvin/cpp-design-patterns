#pragma once
#include "ComputationContext.h"

class BaseComputationCommand {
public:
    virtual bool PreExecute(ComputationContext *context) {
        return true;
    }

    virtual bool Execute(ComputationContext *context) {
        return true;
    }

    virtual bool PostExecute(ComputationContext *context) {
        return true;
    }
};
