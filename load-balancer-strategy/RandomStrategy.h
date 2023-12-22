#pragma once
#include "LoadBalancerStrategy.h"

// Concrete implementation of a random load balancing strategy
class RandomStrategy : public LoadBalancingStrategy {
public:
    int selectServer(const std::vector<int>& serverLoads) const override {
        return rand() % serverLoads.size();
    }
};