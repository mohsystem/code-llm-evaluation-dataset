#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}

void printPreorder(struct Node* node) {
    if (node == NULL)
        return;

    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPostorder(struct Node* node) {
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder traversal of binary tree is 
");
    printPreorder(root);

    printf("
Inorder traversal of binary tree is 
");
    printInorder(root);

    printf("
Postorder traversal of binary tree is 
");
    printPostorder(root);

    return 0;
}