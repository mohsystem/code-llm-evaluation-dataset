#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void preorder_traversal(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void inorder_traversal(struct Node* node) {
    if (node == NULL)
        return;
    inorder_traversal(node->left);
    printf("%d ", node->data);
    inorder_traversal(node->right);
}

void postorder_traversal(struct Node* node) {
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    printf("%d ", node->data);
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;
    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;
    root->right->data = 3;
    root->left->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->right = (struct Node*)malloc(sizeof(struct Node));
    root->left->left->data = 4;
    root->left->right->data = 5;

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\nInorder traversal: ");
    inorder_traversal(root);
    printf("\nPostorder traversal: ");
    postorder_traversal(root);
    return 0;
}