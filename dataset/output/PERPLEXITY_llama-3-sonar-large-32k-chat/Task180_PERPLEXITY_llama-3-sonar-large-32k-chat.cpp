#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    vector<Node*> children;

    Node(int value) : value(value) {}
};

Node* reparentTree(Node* root, Node* newRoot) {
    if (root == newRoot) {
        return root;
    }
    Node* parent = findParent(root, newRoot);
    if (parent) {
        for (auto it = parent->children.begin(); it != parent->children.end(); ++it) {
            if (*it) == newRoot) {
                parent->children.erase(it);
                break;
            }
        }
        newRoot->children.push_back(root);
        return newRoot;
    }
    return root;
}

Node* findParent(Node* root, Node* node) {
    if (root == node) {
        return nullptr;
    }
    for (auto child : root->children) {
        Node* parent = findParent(child, node);
        if (parent) {
            return parent;
        }
    }
    return root;
}

void printTree(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << node->value << endl;
    for (auto child : node->children) {
        printTree(child, level + 1);
    }
}

int main() {
    Node* root = new Node(0);
    root->children.push_back(new Node(1));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[1]->children.push_back(new Node(6));
    root->children[1]->children.push_back(new Node(7));
    root->children[2]->children.push_back(new Node(8));
    root->children[2]->children.push_back(new Node(9));

    Node* newRoot = root->children[1]->children[1];  // Node 6
    newRoot = reparentTree(root, newRoot);

    printTree(newRoot);

    return 0;
}