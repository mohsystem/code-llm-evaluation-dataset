#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr)
            return root->right;
        else if (root->right == nullptr)
            return root->left;
        root->val = minValueNode(root->right)->val;
        root->right = deleteNode(root->right, root->val);
    }
    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == nullptr || root->val == key)
        return root;
    if (root->val < key)
        return searchNode(root->right, key);
    return searchNode(root->left, key);
}

void insert(Node*& root, int key) {
    if (root == nullptr) {
        root = new Node();
        root->val = key;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        if (key < root->val)
            insert(root->left, key);
        else if (key > root->val)
            insert(root->right, key);
    }
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder traversal of the given tree" << endl;
    inorder(root);
    cout << endl;

    cout << "Delete 20" << endl;
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree" << endl;
    inorder(root);
    cout << endl;

    cout << "Search for 40" << endl;
    if (searchNode(root, 40) != nullptr)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}