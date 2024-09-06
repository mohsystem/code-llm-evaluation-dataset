#include <iostream>
#include <queue>
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
    queue<Node*> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node* node = queue.front();
        queue.pop();
        if (node == newRoot) {
            return node;
        }
        for (Node* child : node->children) {
            queue.push(child);
        }
    }
    return nullptr;
}

void printTree(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << node->value << endl;
    for (Node* child : node->children) {
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

    cout << "Original tree:" << endl;
    printTree(root, 0);

    Node* newRoot = reparentTree(root, new Node(6));
    cout << "\nReparented tree:" << endl;
    printTree(newRoot, 0);

    return 0;
}