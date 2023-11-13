#pragma once
#include "IContentWriter.h"
#include "../util/ThreadSafeQueue.h"

class BaseContentWriter : IContentWriter
{
public:
    BaseContentWriter()
    {
        _queue = new ThreadSafeQueue<std::string>();
    };
    ~BaseContentWriter()
    {
        delete _queue;
    };
    //---- Write to Media
    virtual bool WriteToMedia(std::string logcontent) = 0;

    bool Flush()
    {
        std::string content;
        int count = 0;
        while (!_queue->empty() && count <= 10)
        {
            content = std::string(_queue->pop());
            //--- Write to Appropriate Media
            //--- Calls the Overriden method
            WriteToMedia(content);
            count++;
        }
        return true;
    }

    bool Write(std::string content)
    {
        _queue->push(content);
        if (_queue->size() <= 10)
            return true;

        // Do flush in a separate thread
        std::lock_guard<std::mutex> lock(mutex_);
        Flush();

        return true;
    }

private:
    ThreadSafeQueue<std::string> *_queue;
    mutable std::mutex mutex_;
};
