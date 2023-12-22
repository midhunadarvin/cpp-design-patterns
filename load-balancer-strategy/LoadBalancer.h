#pragma once
#include "LoadBalancerStrategy.h"

// Context class that uses the load balancing strategy
class LoadBalancer {
private:
    LoadBalancingStrategy* strategy;
    std::vector<int> serverLoads;

public:
    LoadBalancer(LoadBalancingStrategy* strategy) : strategy(strategy) {}

    void addServer() {
        serverLoads.push_back(0);
    }

    void request() {
        int selectedServer = strategy->selectServer(serverLoads);
        std::cout << "Request sent to server " << selectedServer + 1 << std::endl;
        // Simulate server load increase
        serverLoads[selectedServer]++;
    }
};