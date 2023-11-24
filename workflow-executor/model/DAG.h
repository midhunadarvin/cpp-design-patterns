#pragma once
#include <unordered_set>
#include <stack>
#include "Graph.h"

template <typename T>
class DAG: public Graph<T> {
public:
    // Function to perform a topological sort (helper function)
    void topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& order) {
        visited[v] = true;

        // Recur for all the vertices
        // adjacent to this vertex
        std::vector<int>::iterator i;
        for (i = this->adjacencyList[v].begin(); i != this->adjacencyList[v].end(); ++i)
            if (!visited[*i])
                topologicalSortUtil(*i, visited, order);

        order.push(v);
    }

    // Function to perform a topological sort of the DAG
    void topologicalSort() {
        std::stack<int> order;
        std::vector<bool> visited(this->vertices.size(), false);

        for (Vertex<T> item: this->vertices) {
            if (!visited[item.id]) {
                topologicalSortUtil(item.id, visited, order);
            }
        }

        // Print the topological order
        std::cout << "Topological order of the DAG: ";
        while (!order.empty()) {
            std::cout << order.top() << " ";
            order.pop();
        }
        std::cout << std::endl;
    }
};
