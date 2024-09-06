// CPP code
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data) {
    if (root == NULL) {
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

Node* FindMin(Node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

Node* Delete(Node* root, int data) {
    Node* temp;
    if(root == NULL) return NULL;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else {
        if(root->left && root->right) {
            temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, root->data);
        } else {
            temp = root;
            if(root->left == NULL) root = root->right;
            else if(root->right == NULL) root = root->left;
            delete temp;
        }
    }
    return root;
}

bool Search(Node* root, int data) {
    while(root != NULL) {
        if(root->data > data) root = root->left;
        else if(root->data < data) root = root->right;
        else return true;
    }
    return false;
}