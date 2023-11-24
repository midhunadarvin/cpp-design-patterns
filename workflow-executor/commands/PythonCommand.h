#pragma once
#include "BaseComputationCommand.h"
#include "ComputationContext.h"
#include <fstream>

class PythonCommand: BaseComputationCommand {
public:
    bool Execute(ComputationContext* context) override;
};
