/**
 * Build: g++ -o main.exe main.cpp -std=c++17 -lsqlite3
 * Run  : ./main.exe
 */
#include <iostream>
#include <cstring>
#include "Logger.h"

static bool Table(Logger *ls)
{
    int a = 10;
    int b = 1;
    while (b < 100)
    {
        ls->Log("Table", std::to_string(a) + " * " + std::to_string(b), "=" + std::to_string(a * b));
        b++;
    }
    return true;
}

int main()
{
    /**
     * Creating via Logger singleton class will start a thread, that
     * listens for log inputs and outputs them asyncronously
     */
    Logger *logger = Logger::getInstance();
    //-- somewhere out in the module
    Table(logger);
    return 0;
}