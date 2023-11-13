#pragma once
#include "LogStrategy.h"
#include "../content-writer/BaseContentWriter.h"
#include "../content-writer/FileContentWriter.h"

class FileLogStrategy: public LogStrategy
{
    BaseContentWriter *wt = new FileContentWriter("log.txt");
    bool DoLog(std::string logitem) override
    {
        return wt->Write(logitem);
    }
};
