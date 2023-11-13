#pragma once
#include "BaseContentWriter.h"
#include "../util/TcpClient.h"
#include <string>

class NetworkContentWriter: public BaseContentWriter
{
public:
    static const std::string domain;
    static const int port = 4500;
    bool WriteToMedia(std::string content) override
    {
        TcpClient *_client = new TcpClient(domain.c_str(), port);
        _client->sendTcpMessage(content.c_str());
        return true;
    }
};

const std::string NetworkContentWriter::domain = "127.0.0.1";
