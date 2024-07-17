#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void preorder_traversal(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void inorder_traversal(Node* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
}

void postorder_traversal(Node* node) {
    if (node == nullptr) return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = new Node{1};
    root->left = new Node{2};
    root->right = new Node{3};
    root->left->left = new Node{4};
    root->left->right = new Node{5};

    cout << "Preorder traversal: ";
    preorder_traversal(root);
    cout << "
Inorder traversal: ";
    inorder_traversal(root);
    cout << "
Postorder traversal: ";
    postorder_traversal(root);
    return 0;
}