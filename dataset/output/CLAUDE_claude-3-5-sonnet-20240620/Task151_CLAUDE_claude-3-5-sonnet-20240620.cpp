
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

    Node* insertRec(Node* root, int key) {
        if (root == nullptr) return new Node(key);
        if (key < root->key)
            root->left = insertRec(root->left, key);
        else if (key > root->key)
            root->right = insertRec(root->right, key);
        return root;
    }

    Node* deleteRec(Node* root, int key) {
        if (root == nullptr) return root;
        if (key < root->key)
            root->left = deleteRec(root->left, key);
        else if (key > root->key)
            root->right = deleteRec(root->right, key);
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
            root->right = deleteRec(root->right, temp->key);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* searchRec(Node* root, int key) {
        if (root == nullptr || root->key == key)
            return root;
        if (root->key < key)
            return searchRec(root->right, key);
        return searchRec(root->left, key);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void deleteKey(int key) {
        root = deleteRec(root, key);
    }

    Node* search(int key) {
        return searchRec(root, key);
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

    bst.deleteKey(40);
    std::cout << "Search for 40 after deletion: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;

    return 0;
}
