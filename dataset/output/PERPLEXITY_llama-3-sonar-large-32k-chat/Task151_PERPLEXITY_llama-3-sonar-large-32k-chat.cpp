#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int item) {
        val = item;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }
        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                node = nullptr;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                node = nullptr;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }

    Node* searchNode(Node* node, int val) {
        if (node == nullptr || node->val == val) {
            return node;
        }
        if (node->val < val) {
            return searchNode(node->right, val);
        } else {
            return searchNode(node->left, val);
        }
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->val << " ";
            inorder(node->right);
        }
    }
};

int main() {
    BinaryTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);

    cout << "Inorder traversal of the given tree" << endl;
    tree.inorder(tree.root);

    cout << "\nDelete 20" << endl;
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "Inorder traversal of the modified tree" << endl;
    tree.inorder(tree.root);

    cout << "\nSearch for 40" << endl;
    Node* res = tree.searchNode(tree.root, 40);
    if (res != nullptr) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}