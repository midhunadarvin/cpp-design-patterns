#pragma once
#include "LogStrategy.h"
#include "../content-writer/NetworkContentWriter.h"

class NetLogStrategy: public LogStrategy {
    BaseContentWriter *nc = new NetworkContentWriter();
    bool DoLog(std::string logitem) override {
           // Log into the Network Socket
           nc->Write(logitem);
           return true;
    } 
};
