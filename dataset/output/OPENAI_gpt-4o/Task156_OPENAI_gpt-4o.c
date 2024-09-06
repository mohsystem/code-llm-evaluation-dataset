#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left, * right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct Node* node) {
    if (node == NULL)
        return;
    
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder traversal of binary tree is ");
    inorder(root);

    return 0;
}