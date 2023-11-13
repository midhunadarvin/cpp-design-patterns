#pragma once
#include <string>

class LogStrategy
{
public:
    // DoLog is our Template method
    // Concrete classes will override this
    virtual bool DoLog(std::string logitem) = 0;
    bool Log(std::string app, std::string key, std::string cause)
    {
        return DoLog(app + " " + key + " " + cause);
    }
};
