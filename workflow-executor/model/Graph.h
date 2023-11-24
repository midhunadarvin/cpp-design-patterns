#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

enum EdgeType {
    DIRECTED,
    UNDIRECTED
};

template<typename T>
class Vertex {
public:
    int id;
    T data;                                        // Return the element associated with vertex
    Vertex(int id, T data) : id(id), data(data) {}  // Constructor
    Vertex(T data): data(data) {};
    Vertex() {};
//    bool isAdjacentTo(Vertex<T> v);                 // Test whether vertices u and v are adjacent
};

template<typename T>
class Edge {
public:
    std::pair<Vertex<T>, Vertex<T> > endVertices;
//    std::vector<Vertex<T> > endVertices();  // Return a vertex list containing e’s end vertices.
//    Vertex<T> opposite(
//            Vertex<T> v);        // Return the end vertex of edge e distinct from vertex v; an error occurs if e is not incident on v.
//    bool isAdjacentTo(Edge f);              // Test whether edges e and f are adjacent.
//    bool isIncidentOn(Vertex<T> v);         // Test whether e is incident on v.
};


template<typename T>
class Graph {
protected:
    std::unordered_map<int, std::vector<int> > adjacencyList;
    std::vector<Vertex<T>> vertices;              // Return a vertex list of all the vertices of the graph.
    std::vector<Edge<T> > edges;                   // Return an edge list of all the edges of the graph.
public:
    // Insert and return a new vertex storing element x.
    bool insertVertex(T v) {
        Vertex<T> a;
        a.data = v;
        a.id = vertices.size();
        vertices.push_back(a);
        adjacencyList[a.id] = std::vector<int>();
        return true;
    }

    Vertex<T> findVertex(T x) {
        typename std::vector<Vertex<T>>::iterator it = find_if(vertices.begin(), vertices.end(),
                                                               [x](const Vertex<T> &val) {
                                                                   return val.data == x;
                                                               });
        if (it == vertices.end()) {
            throw std::runtime_error("No vertex found!");
        }
        return *it;
    }

    bool checkIfVertexExists(Vertex<T> v) {
        return adjacencyList.find(v.id) != adjacencyList.end();
    }

    // Insert edge with just types
    bool insertEdge(T v, T w, EdgeType edgeType = EdgeType::DIRECTED) {
        Vertex<T> a = findVertex(v);
        Vertex<T> b = findVertex(w);
        return insertEdge(a, b, edgeType);
    }

    // Insert and return a new undirected edge with end vertices v and w.
    bool insertEdge(Vertex<T> v, Vertex<T> w, EdgeType edgeType = EdgeType::DIRECTED) {
        if (checkIfVertexExists(v) && checkIfVertexExists(w)) {
            Edge<T> e;
            e.endVertices = std::make_pair(v, w);
            edges.push_back(e);
            adjacencyList[v.id].push_back(w.id);
            if (edgeType == EdgeType::UNDIRECTED) {
                adjacencyList[w.id].push_back(v.id);
            }
            return true;
        } else {
            return false;
        }
    }

    // Remove edge e.
    void removeEdge(Edge<T> e) {
        Vertex<T> v = e.endVertices.first;
        Vertex<T> w = e.endVertices.second;
        removeEdge(v, w);
    }
    // Function to remove an edge from the graph
    void removeEdge(Vertex<T> v, Vertex<T> w) {
        if (checkIfVertexExists(v) && checkIfVertexExists(w)) {
            auto it = find(adjacencyList[v.id].begin(), adjacencyList[v.id].end(), w.id);
            if (it != adjacencyList[v.id].end()) {
                adjacencyList[v.id].erase(it);
            }

            it = find(adjacencyList[w.id].begin(), adjacencyList[w.id].end(), v.id);
            if (it != adjacencyList[w.id].end()) {
                adjacencyList[w.id].erase(it);
            }
        }
    }

    void removeVertex(T x) {
        Vertex<T> v = findVertex(x);
        removeVertex(v);
    }

    // Function to remove a vertex from the graph
    void removeVertex(Vertex<T> v) {
        // Remove edges associated with the vertex
        adjacencyList[v.id].clear();

        // Remove the vertex from the adjacency lists of other vertices
        for (auto vertex: vertices) {
            auto it = find(adjacencyList[vertex.id].begin(), adjacencyList[vertex.id].end(), v.id);
            if (it != adjacencyList[vertex.id].end()) {
                adjacencyList[vertex.id].erase(it);
            }
        }
        adjacencyList.erase(v.id);

        // Remove from vertices
        auto it = find_if(vertices.begin(), vertices.end(), [v](const Vertex<T>& val) { return v.id == val.id; });
        if (it != vertices.end())
            vertices.erase(it);
    }

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for (const auto &kv: adjacencyList) {
            std::cout << "Adjacency list of vertex " << kv.first << ": ";
            for (const auto &neighbor: kv.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};
