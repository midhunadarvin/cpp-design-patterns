/**
 * Load balancing using strategy pattern
 * Build : g++ -o main.exe main.cpp -std=c++17
 * Run: ./main.exe
*/
#include "LoadBalancer.h"
#include "RoundRobinStrategy.h"
#include "RandomStrategy.h"

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Create load balancer with round-robin strategy
    LoadBalancer roundRobinBalancer(new RoundRobinStrategy());

    // Add servers to the load balancer
    roundRobinBalancer.addServer();
    roundRobinBalancer.addServer();
    roundRobinBalancer.addServer();

    // Simulate incoming requests
    for (int i = 0; i < 10; ++i) {
        roundRobinBalancer.request();
    }

    std::cout << std::endl;

    // Create load balancer with random strategy
    LoadBalancer randomBalancer(new RandomStrategy());

    // Add servers to the load balancer
    randomBalancer.addServer();
    randomBalancer.addServer();
    randomBalancer.addServer();

    // Simulate incoming requests
    for (int i = 0; i < 10; ++i) {
        randomBalancer.request();
    }

    return 0;
}