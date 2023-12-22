#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>

// Abstract base class for load balancing strategies
class LoadBalancingStrategy {
public:
    virtual int selectServer(const std::vector<int>& serverLoads) const = 0;
    virtual ~LoadBalancingStrategy() = default;
};
