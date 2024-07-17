#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int key) {
        if (node == NULL) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return root;
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;

            root->key = minValue(root->right);
            root->right = deleteNode(root->right, root->key);
        }
        return root;
    }

    int minValue(Node* node) {
        int minv = node->key;
        while (node->left != NULL) {
            minv = node->left->key;
            node = node->left;
        }
        return minv;
    }

    Node* search(Node* root, int key) {
        if (root == NULL || root->key == key)
            return root;
        if (root->key < key)
            return search(root->right, key);
        return search(root->left, key);
    }

    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
};

int main() {
    BST bst;
    bst.root = bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 60);
    bst.insert(bst.root, 80);

    Node* found = bst.search(bst.root, 40);
    if (found) cout << found->key << endl;

    bst.root = bst.deleteNode(bst.root, 20);
    cout << (bst.search(bst.root, 20) != NULL ? "Found!" : "Not Found!") << endl;

    return 0;
}