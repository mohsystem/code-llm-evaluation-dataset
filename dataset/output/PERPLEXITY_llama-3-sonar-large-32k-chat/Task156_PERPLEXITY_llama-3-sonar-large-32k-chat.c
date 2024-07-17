#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void preorder_traversal(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void inorder_traversal(Node* node) {
    if (node == NULL) return;
    inorder_traversal(node->left);
    printf("%d ", node->data);
    inorder_traversal(node->right);
}

void postorder_traversal(Node* node) {
    if (node == NULL) return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    printf("%d ", node->data);
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = 1;
    root->left = (Node*)malloc(sizeof(Node));
    root->right = (Node*)malloc(sizeof(Node));
    root->left->data = 2;
    root->right->data = 3;
    root->left->left = (Node*)malloc(sizeof(Node));
    root->left->right = (Node*)malloc(sizeof(Node));
    root->left->left->data = 4;
    root->left->right->data = 5;

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("
Inorder traversal: ");
    inorder_traversal(root);
    printf("
Postorder traversal: ");
    postorder_traversal(root);
    return 0;
}