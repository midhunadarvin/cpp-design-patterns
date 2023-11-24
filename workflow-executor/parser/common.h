#pragma once
#include "tinyxml2.h"

using namespace tinyxml2;

void XMLCheckResult(XMLError a_eResult) {
    if (a_eResult != XML_SUCCESS) {
        printf("Error: %i\n", a_eResult);
        throw std::runtime_error(std::to_string(a_eResult));
    }
}
