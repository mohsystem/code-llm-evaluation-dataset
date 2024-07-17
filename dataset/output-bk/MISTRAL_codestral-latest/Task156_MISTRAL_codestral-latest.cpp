#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void printPreorder(Node* node) {
    if (node == NULL)
        return;

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(Node* node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPostorder(Node* node) {
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder traversal of binary tree is 
";
    printPreorder(root);

    cout << "
Inorder traversal of binary tree is 
";
    printInorder(root);

    cout << "
Postorder traversal of binary tree is 
";
    printPostorder(root);

    return 0;
}