#include <iostream>
#include <vector>

class Node {
public:
    int data;
    std::vector<Node*> children;

    Node(int data) {
        this->data = data;
    }

    void reparent(Node* parent) {
        children.erase(std::remove(children.begin(), children.end(), parent), children.end());
        for (Node* child : children) {
            child->reparent(this);
        }
    }

    void printTree(int level) {
        for (int i = 0; i < level; i++) {
            std::cout << " ";
        }
        std::cout << data << std::endl;
        for (Node* child : children) {
            child->printTree(level + 1);
        }
    }
};