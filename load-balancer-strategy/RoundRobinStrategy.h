#pragma once
#include "LoadBalancerStrategy.h"

// Concrete implementation of a round-robin load balancing strategy
class RoundRobinStrategy : public LoadBalancingStrategy {
public:
    int selectServer(const std::vector<int>& serverLoads) const override {
        static int currentIndex = -1;
        currentIndex = (currentIndex + 1) % serverLoads.size();
        return currentIndex;
    }
};