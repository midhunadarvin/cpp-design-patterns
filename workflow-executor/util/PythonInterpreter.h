//
// Created by Midhun Darvin on 08/11/23.
//
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <string>
#include "../commands/ComputationContext.h"
#pragma once

class PythonInterpreter {
public:
    PythonInterpreter() {
        // Initialize python
        Py_Initialize();
    }
    ~PythonInterpreter() {
        Py_Finalize();
    }

    int Execute(std::string filename, ComputationContext *context);
};


