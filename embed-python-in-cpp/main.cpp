/**
 * g++ -o main.exe $(python3-config --cflags) main.cpp /opt/homebrew/Cellar/python@3.11/3.11.6_1/Frameworks/Python.framework/Versions/Current/lib/libpython3.11.dylib
 * Compile: g++ main.cpp -c $(python3-config --cflags) -fPIC
 * Link   : g++ main.o $(python3-config --ldflags) -o main.exe
 * Run    : main.exe multiply <arg-1> <arg-2>
 */
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>

PyObject *createExecutionContext(char *a, char *b)
{
    // Create a Python dictionary
    PyObject *dict = PyDict_New();
    if (!dict)
    {
        PyErr_Print();
        return nullptr;
    }

    // Add key-value pairs to the dictionary
    PyObject *key1 = PyUnicode_DecodeUTF8("key1", 4, "strict");
    PyObject *value1 = PyUnicode_DecodeUTF8(a, strlen(a), "strict");
    PyDict_SetItem(dict, key1, value1);

    PyObject *key2 = PyUnicode_DecodeUTF8("key2", 4, "strict");
    PyObject *value2 = PyUnicode_DecodeUTF8(b, strlen(b), "strict");
    PyDict_SetItem(dict, key2, value2);

    // Print the dictionary
    PyObject_Print(dict, stdout, 0);
    printf("\n");
    return dict;
}

int main(int argc, char *argv[])
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL)
    {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }

    PyObject *pName, *pModule;
    PyObject *preExecuteFunc, *executeFunc, *postExecuteFunc;
    PyObject *pArgs, *pValue;

    // Initialize python
    Py_Initialize();

    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");

    pName = PyUnicode_DecodeFSDefault(argv[1]);
    /* Error checking of pName left out */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL)
    {

        preExecuteFunc = PyObject_GetAttrString(pModule, "preExecute");
        executeFunc = PyObject_GetAttrString(pModule, "execute");
        postExecuteFunc = PyObject_GetAttrString(pModule, "postExecute");

        PyObject *executionContext = createExecutionContext(argv[2], argv[3]);
        PyObject *pArgs = PyTuple_New(1);
        PyTuple_SetItem(pArgs, 0, executionContext);
        if (preExecuteFunc && PyCallable_Check(preExecuteFunc))
        {
            PyObject *preExecuteResult = PyObject_CallObject(preExecuteFunc, pArgs);
            if (preExecuteResult != NULL)
            {
                std::cout << "PreExecute :" << Py_IsTrue(preExecuteResult) << std::endl;
                if (Py_IsTrue(preExecuteResult))
                {
                    if (executeFunc && PyCallable_Check(executeFunc))
                    {
                        PyObject *executeFuncResult = PyObject_CallObject(executeFunc, pArgs);
                        std::cout << "Execute :" << Py_IsTrue(executeFuncResult) << std::endl;
                        Py_DECREF(executeFuncResult);
                    }
                    else
                    {
                        if (PyErr_Occurred())
                            PyErr_Print();
                        fprintf(stderr, "Cannot find function \"%s\"\n", "preExecute");
                        Py_DECREF(executeFunc);
                        Py_DECREF(pModule);
                    }

                    if (postExecuteFunc && PyCallable_Check(postExecuteFunc))
                    {
                        PyObject *postExecuteFuncResult = PyObject_CallObject(postExecuteFunc, pArgs);
                        std::cout << "PostExecute :" << Py_IsTrue(postExecuteFuncResult) << std::endl;
                        Py_DECREF(postExecuteFuncResult);
                    }
                    else
                    {
                        if (PyErr_Occurred())
                            PyErr_Print();
                        fprintf(stderr, "Cannot find function \"%s\"\n", "preExecute");
                        Py_DECREF(postExecuteFunc);
                        Py_DECREF(pModule);
                    }
                }
                Py_DECREF(preExecuteResult);
            }
        }
        else
        {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", "preExecute");
        }

        Py_DECREF(pModule);
    }
    else
    {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", argv[1]);
        return 1;
    }

    if (Py_FinalizeEx() < 0)
    {
        exit(120);
    }
    PyMem_RawFree(program);
    return 0;
}