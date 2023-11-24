#pragma once

#include "tinyxml2.h"
#include "../model/Tree.h"
#include "common.h"

using namespace tinyxml2;

class XmlTreeParser {
public:
    Tree<std::string> *parse(std::string fileName) {
        XMLDocument xmlDoc;
        XMLError eResult = xmlDoc.LoadFile(fileName.c_str());
        XMLCheckResult(eResult);

//        Tree<std::string> tree;
        XMLNode *docRoot = xmlDoc.FirstChildElement("tree");
        if (docRoot == nullptr) {
            throw std::runtime_error(std::to_string(XML_ERROR_FILE_READ_ERROR));
        }

        XMLElement *treeRootElement = docRoot->FirstChildElement("node");
        if (treeRootElement == nullptr) {
            throw std::runtime_error(std::to_string(XML_ERROR_FILE_READ_ERROR));
        }
        auto *tree = new Tree<std::string>(treeRootElement->Attribute("value"));
        constructTree(treeRootElement, tree->getRoot(), tree);
//        return ParseConfiguration(&xmlDoc);
        return tree;
    }

    void constructTree(XMLElement *node, TreeNode<std::string> *treeNode, Tree<std::string> *tree) {
            XMLElement *childrenElement = node->FirstChildElement("children");
            if (childrenElement == nullptr) {
                return;
            }

            XMLElement *child = childrenElement->FirstChildElement("node");
            while (child) {
                TreeNode<std::string> *childNode = tree->addChild(treeNode, child->Attribute("value"));
                constructTree(child, childNode, tree);
                child = child->NextSiblingElement("node");
            }
    }
};

