#include "commands/BaseComputationCommand.h"
#include <string>
#include <unordered_map>
#include "commands/SeniorCitizenCommand.h"
#include "commands/OrdinaryCitizenCommand.h"
#include "util/globothy.h"
#include "util/libnameothy.h"
#include <set>
#include <dlfcn.h>

class TypeFactory
{
private:
    std::unordered_map<std::string, BaseComputationCommand *> commands_map;
    std::set<std::string> libNames;

public:
    TypeFactory()
    {
        updateLibs();
        for(std::string plugin : libNames) {
            
            void *dlhandle = dlopen(plugin.c_str(), RTLD_LAZY);

            std::pair<std::string, std::string> delibbed =
                libnameothy(plugin);

            BaseComputationCommand *(*create)();
            void (*destroy)(BaseComputationCommand *);

            std::string cn = "create" + delibbed.second;
            std::string dn = "destroy" + delibbed.second;

            create = (BaseComputationCommand *(*)())dlsym(dlhandle, cn.c_str());
            destroy = (void (*)(BaseComputationCommand *))dlsym(dlhandle, dn.c_str());

            BaseComputationCommand *a = create();
            commands_map[delibbed.second] = a;
        }
    };

    void updateLibs();
    BaseComputationCommand *GetType(std::string type);
};
