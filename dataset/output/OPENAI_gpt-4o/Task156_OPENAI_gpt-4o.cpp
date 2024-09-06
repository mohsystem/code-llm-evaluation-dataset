#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left, * right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

void inorder(Node* node) {
    if (node == nullptr)
        return;

    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder traversal of binary tree is ";
    inorder(root);

    return 0;
}