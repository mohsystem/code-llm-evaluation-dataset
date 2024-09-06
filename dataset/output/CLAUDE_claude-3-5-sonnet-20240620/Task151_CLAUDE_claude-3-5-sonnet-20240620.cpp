
#include <iostream>

class Node {
public:
    int key;
    Node *left, *right;

    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* root, int key) {
        if (root == nullptr) return new Node(key);
        if (key < root->key)
            root->left = insertRecursive(root->left, key);
        else if (key > root->key)
            root->right = insertRecursive(root->right, key);
        return root;
    }

    Node* deleteRecursive(Node* root, int key) {
        if (root == nullptr) return root;
        if (key < root->key)
            root->left = deleteRecursive(root->left, key);
        else if (key > root->key)
            root->right = deleteRecursive(root->right, key);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteRecursive(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    bool searchRecursive(Node* root, int key) {
        if (root == nullptr || root->key == key)
            return root != nullptr;
        if (key < root->key)
            return searchRecursive(root->left, key);
        return searchRecursive(root->right, key);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    void remove(int key) {
        root = deleteRecursive(root, key);
    }

    bool search(int key) {
        return searchRecursive(root, key);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not Found") << std::endl;

    bst.remove(40);
    std::cout << "Search for 40 after deletion: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;

    return 0;
}
