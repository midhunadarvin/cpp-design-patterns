#include "commands/BaseComputationCommand.h"
#include "TypeFactory.h"
#include <cstdlib>
#include <string>

void TypeFactory::updateLibs()
{
    std::cout << "Checking for new libs" << std::endl;
    std::string pluginsFolderPath = std::getenv("PLUGINS_FOLDER_PATH");

#if __APPLE__
    const std::string libGlob(pluginsFolderPath + "/*.dylib");
#else
    const std::string libGlob(pluginsFolderPath + "/*.so");
#endif

    std::vector<std::string> filenames = globothy(libGlob);

    size_t before = libNames.size();
    // libLock.lock(); // get locked, boi ------------------------------//
    for (std::string plugin : filenames)
    {                            //
        libNames.insert(plugin); //
    }                            //
    // libLock.unlock();            // got 'em ------------------------------------//
    size_t after = libNames.size();

    if (after - before > 0)
    {
        std::cout << "Found " << after - before << " new plugins";
        std::cout << std::endl;
    }
}

BaseComputationCommand *TypeFactory::GetType(std::string type)
{
    return commands_map[type];

    // if (getUnmangledName(ti) == classname)
    // {
    //     cmd = new SeniorCitizenCommand(); // Replace with actual creation logic.
    // }
    // else
    // {
    //     // You need to map class names to actual derived classes in your application.
    //     // Here, we assume DerivedComputationCommand is the derived class for the archetype.
    //     cmd = new OrdinaryCitizenCommand(); // Replace with actual creation logic.
    // }
};