#pragma once
#include "Graph.h"
#include <queue>
// Node structure for the tree
template <typename T>
struct TreeNode: public Vertex<T> {

    std::vector<TreeNode*> children;

    // Constructor
    TreeNode(const T& value) : Vertex<T>(value) {
    }

    // Destructor to free allocated memory
    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
};

// Tree class
template <typename T>
class Tree: Graph<T> {
private:
    TreeNode<T>* root;

public:
    // Constructor
    Tree(const T& rootData) {
        root = new TreeNode<T>(rootData);
    }

    // Destructor
    ~Tree() {
        delete root;
    }

    // Function to get the root of the tree
    TreeNode<T>* getRoot() const {
        return root;
    }

    // Function to add a child to a given parent node
    TreeNode<T>* addChild(TreeNode<T>* parent, const T& data) {
        TreeNode<T>* newNode = new TreeNode<T>(data);
        parent->children.push_back(newNode);
        return newNode;
    }

    // Function to traverse and print the tree (depth-first)
    void depthFirstSearch(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";

        for (TreeNode<T>* child : node->children) {
            depthFirstSearch(child);
        }
    }

    // Function to traverse and print the tree (breadth-first)
    void breadthFirstSearch(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        std::queue<TreeNode<T>*> que;
        que.push(node);

        while (!que.empty()) {
            TreeNode<T> *temp = que.front();
            que.pop();
            std::cout << temp->data << " ";
            for (TreeNode<T>* child : temp->children) {
                que.push(child);
            }
        }
    }

    // Function to print the entire tree
    void printTree() {
        depthFirstSearch(root);
        std::cout << std::endl;
        breadthFirstSearch(root);
        std::cout << std::endl;
    }
};