#pragma once

#include <iostream>
#include <vector>
#import "../commands/PythonCommand.h"
#import "../commands/CommandAttributes.h"

class WorkflowExecutor {
private:
    std::vector<std::vector<CommandAttributes>> workflows;
public:
    WorkflowExecutor(std::vector<std::vector<CommandAttributes>> workflows) {
        this->workflows = workflows;
    }

    void execute() {
        ComputationContext computationContext;
        std::unordered_map<std::string, std::string> prev_responses;
        for (std::vector<CommandAttributes> workflow: workflows) {
            for (CommandAttributes commandAttr: workflow) {
                PythonCommand *command = new PythonCommand();

                computationContext.Put("name", commandAttr.name);
                for (const auto& prev_response: prev_responses) {
                    commandAttr.params[prev_response.first] = prev_response.second;
                }
                computationContext.Put("params", commandAttr.params);
                command->Execute(&computationContext);
                prev_responses[commandAttr.name + "_response"] = std::any_cast<std::string>(computationContext.Get("response"));
            }
        }
    }
};
