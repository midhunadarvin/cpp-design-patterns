#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "tinyxml2.h"

class XMLHelper {
    public:
        static std::unordered_map<std::string, std::string> LoadConfig(std::string filePath);
};