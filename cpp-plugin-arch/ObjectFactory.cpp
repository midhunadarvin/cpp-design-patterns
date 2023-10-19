#include "util/XMLHelper.h"
#include <unordered_map>
#include <typeinfo> // Include the header for typeid
#include <memory>   // Include the header for std::make_shared
#include <cxxabi.h> // For demangling
#include "ObjectFactory.h"
#include "commands/BaseComputationCommand.h"
#include "TypeFactory.h"

std::shared_ptr<BaseComputationCommand> ObjectFactory::Get(std::string archetype, std::string mode)
{
    //---- We can create a new instance, when a
    //---- prototype is asked, otherwise we will
    //---- return the same instance stored in the dictionary
    if (mode != "singleton" && mode != "prototype")
        throw "Must be a valid mode parameter!";

    std::shared_ptr<BaseComputationCommand> temp = nullptr;
    //--- if an instance is already found, return
    // it (singleton) or clone (prototype
    if (commands.find(archetype) != commands.end())
    {
        temp = commands[archetype];
        if (mode == "singleton")
        {
            return temp;
        }
        else
        {
            return temp->Clone();
        }
    }


    //---- retrieve the commandclass name
    std::string classname = plugins[archetype];
    if (classname.empty())
    {
        return nullptr;
    }

    TypeFactory *typeFactory = new TypeFactory();
    BaseComputationCommand *cmd = nullptr;
    cmd = typeFactory->GetType(classname);


    commands[archetype] = std::shared_ptr<BaseComputationCommand>(cmd);
    return commands[archetype];
}