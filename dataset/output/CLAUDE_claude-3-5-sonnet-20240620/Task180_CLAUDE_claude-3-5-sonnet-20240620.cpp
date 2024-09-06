
#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
    int data;
    std::vector<Node*> children;

    Node(int data) : data(data) {}
};

Node* findNode(Node* node, int data) {
    if (node->data == data) {
        return node;
    }
    for (Node* child : node->children) {
        Node* result = findNode(child, data);
        if (result) {
            return result;
        }
    }
    return nullptr;
}

void reparentHelper(Node* node, Node* parent) {
    if (parent) {
        node->children.erase(std::remove(node->children.begin(), node->children.end(), parent), node->children.end());
        node->children.push_back(parent);
    }
    for (Node* child : std::vector<Node*>(node->children)) {
        if (child != parent) {
            reparentHelper(child, node);
        }
    }
}

Node* reparent(Node* root, int newRootData) {
    Node* newRoot = findNode(root, newRootData);
    if (!newRoot) {
        return root;
    }

    reparentHelper(newRoot, nullptr);
    return newRoot;
}

void printTree(Node* node, int level = 0) {
    std::cout << std::string(level * 2, ' ') << node->data << std::endl;
    for (Node* child : node->children) {
        printTree(child, level + 1);
    }
}

int main() {
    Node* root = new Node(0);
    root->children = {new Node(1), new Node(2), new Node(3)};
    root->children[0]->children = {new Node(4), new Node(5)};
    root->children[1]->children = {new Node(6), new Node(7)};
    root->children[2]->children = {new Node(8), new Node(9)};

    std::cout << "Original tree:" << std::endl;
    printTree(root);

    Node* newRoot = reparent(root, 6);
    std::cout << "\\nReparented tree with 6 as root:" << std::endl;
    printTree(newRoot);

    return 0;
}
