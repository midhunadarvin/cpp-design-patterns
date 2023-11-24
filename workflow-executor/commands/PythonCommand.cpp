#include "PythonCommand.h"
#include "../util/PythonInterpreter.h"

extern "C" PythonCommand *createPythonCommand() {
    return new PythonCommand;
}

extern "C" void destroyPythonCommand(PythonCommand *c) {
    delete c;
}

bool PythonCommand::Execute(ComputationContext *context) {
    try {
        /**
         * Find python file and execute it.
         */
        PythonInterpreter pythonInterpreter;

        ComputationContext *pythonComputationContext = new ComputationContext;

        auto params = std::any_cast<std::unordered_map<std::string, std::string>>(context->Get("params"));
        PyObject *pyParams = PyDict_New();
        for (const auto& param : params) {
            PyObject* strA = PyUnicode_FromString(param.first.c_str());
            PyObject* strB = PyUnicode_FromString(param.second.c_str());
            PyDict_SetItem(pyParams, strA, strB);
            Py_XDECREF(strA);
            Py_XDECREF(strB);
        }
        pythonComputationContext->Put("params", context->Get("params"));

        pythonInterpreter.Execute(std::any_cast<std::string>(context->Get("name")), pythonComputationContext);
        auto content = std::any_cast<std::string>(pythonComputationContext->Get("response"));

        context->Put("response", content);

        return true;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }

}
