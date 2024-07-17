#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node *root;

    BinaryTree() {
        root = nullptr;
    }

    void preorderTraversal(Node *node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void inorderTraversal(Node *node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void postorderTraversal(Node *node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Preorder traversal: ";
    tree.preorderTraversal(tree.root);
    cout << endl;

    cout << "Inorder traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorderTraversal(tree.root);
    cout << endl;

    return 0;
}