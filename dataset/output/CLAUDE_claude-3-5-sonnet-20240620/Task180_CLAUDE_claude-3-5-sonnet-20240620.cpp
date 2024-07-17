
#include <iostream>
#include <vector>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int val) : value(val) {}
};

Node* findNode(Node* node, int value) {
    if (node->value == value) {
        return node;
    }
    for (Node* child : node->children) {
        Node* result = findNode(child, value);
        if (result) {
            return result;
        }
    }
    return nullptr;
}

void reparentHelper(Node* node, Node* parent) {
    std::vector<Node*> newChildren;
    for (Node* child : node->children) {
        if (child != parent) {
            newChildren.push_back(child);
        }
    }
    if (parent) {
        newChildren.push_back(parent);
    }
    node->children = newChildren;
    for (Node* child : node->children) {
        reparentHelper(child, node);
    }
}

Node* reparent(Node* root, int newRootValue) {
    Node* newRoot = findNode(root, newRootValue);
    if (!newRoot) {
        return root;
    }

    reparentHelper(newRoot, nullptr);
    return newRoot;
}

void printTree(Node* node, int level = 0) {
    std::cout << std::string(level * 2, \' \') << node->value << std::endl;
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
    std::cout << "\
Reparented tree with 6 as root:" << std::endl;
    printTree(newRoot);

    return 0;
}
