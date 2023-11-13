/**
 * Build: g++ -o main.exe main.cpp -std=c++17 -lsqlite3
 * Run  : ./main.exe
 */
#include <iostream>
#include <cstring>
#include "LoggerFactory.h"
#include "strategy/LogStrategy.h"

static bool Table(LogStrategy *ls)
{
    int a = 10;
    int b = 1;
    while (b < 100)
    {
        ls->Log("Table", std::to_string(a) + " * " + std::to_string(b), "=" + std::to_string(a*b));
        b++;
    }
    return true;
}

int main()
{
    // TODO: Read this from a configuration file
    std::string loggertype = "FILE";

    LogStrategy *lf = LoggerFactory::CreateLogger(loggertype);
    //-- somewhere out in the module
    Table(lf);

    return 0;
}