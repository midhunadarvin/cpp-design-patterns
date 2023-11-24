#pragma once
#include <string>
#include <unordered_map>
#include <any>

class CommandAttributes {
public:
    std::string name;
    std::unordered_map<std::string, std::string> params;
};