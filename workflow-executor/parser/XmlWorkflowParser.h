#pragma once

#include "tinyxml2.h"
#include "common.h"
#include "../commands/CommandAttributes.h"
#include "../model/Tree.h"

using namespace tinyxml2;

class XmlWorkflowParser {
public:
    std::vector<std::vector<CommandAttributes>> parse(std::string fileName) {
        XMLDocument xmlDoc;
        XMLError eResult = xmlDoc.LoadFile(fileName.c_str());
        XMLCheckResult(eResult);

        XMLNode *docRoot = xmlDoc.FirstChildElement("workflow");
        if (docRoot == nullptr) {
            throw std::runtime_error(std::to_string(XML_ERROR_FILE_READ_ERROR));
        }

        XMLElement *levelElement = docRoot->FirstChildElement("level");
        if (levelElement == nullptr) {
            throw std::runtime_error(std::to_string(XML_ERROR_FILE_READ_ERROR));
        }
        int level = 1;
        std::vector<std::vector<CommandAttributes>> result;
        while (levelElement) {
            if (result.size() < level) {
                while (result.size() < level) {
                    result.push_back(std::vector<CommandAttributes>());
                }
            }
            XMLElement *workflowItemElement = levelElement->FirstChildElement("workflow-item");
            while (workflowItemElement) {
                CommandAttributes commandAttr;
                XMLElement *commandElement = workflowItemElement->FirstChildElement("command");
                commandAttr.name = commandElement->GetText();

                XMLElement *paramsElement = workflowItemElement->FirstChildElement("params");
                XMLElement *paramElement = paramsElement->FirstChildElement("param");
                std::unordered_map<std::string, std::string> params;
                while (paramElement) {
                    params[paramElement->Attribute("id")] = paramElement->Attribute("value");
                    paramElement = paramElement->NextSiblingElement("param");
                }
                commandAttr.params = params;
                result[level - 1].push_back(commandAttr);
                workflowItemElement = workflowItemElement->NextSiblingElement("workflow-item");
            }
            levelElement = levelElement->NextSiblingElement("level");
            level+=1;
        }
        return result;
    }
};

