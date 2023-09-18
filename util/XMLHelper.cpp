#include "XMLHelper.h"
#include <utility>
using namespace tinyxml2;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult)         \
    if (a_eResult != XML_SUCCESS)         \
    {                                     \
        printf("Error: %i\n", a_eResult); \
        return a_eResult;                 \
    }
#endif

std::unordered_map<std::string, std::string> XMLHelper::LoadConfig(std::string filePath)
{
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(filePath.c_str());
    if (eResult != XML_SUCCESS) {
        throw "Failed to load xml file!";
    };

    XMLNode *plugins = xmlDoc.FirstChildElement("plugins");
    if (plugins == nullptr)
    {
        throw "Failed to read plugins from config file!";
    }

    XMLElement *pluginElement = plugins->FirstChildElement("plugin");
    std::unordered_map<std::string, std::string> config;
    while (pluginElement)
    {
        config.insert(std::make_pair<std::string, std::string>(pluginElement->Attribute("archetype"), pluginElement->Attribute("command")));

        pluginElement = pluginElement->NextSiblingElement("plugin");
    }
    return config;
}