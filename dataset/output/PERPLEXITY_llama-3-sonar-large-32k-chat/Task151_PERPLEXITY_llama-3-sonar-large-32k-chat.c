#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        root->val = minValueNode(root->right)->val;
        root->right = deleteNode(root->right, root->val);
    }
    return root;
}

Node* searchNode(Node* root, int key) {
    if (root == NULL || root->val == key)
        return root;
    if (root->val < key)
        return searchNode(root->right, key);
    return searchNode(root->left, key);
}

void insert(Node** root, int key) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->val = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else {
        if (key < (*root)->val)
            insert(&((*root)->left), key);
        else if (key > (*root)->val)
            insert(&((*root)->right), key);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of the given tree
");
    inorder(root);
    printf("
");

    printf("Delete 20
");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree
");
    inorder(root);
    printf("
");

    printf("Search for 40
");
    if (searchNode(root, 40) != NULL)
        printf("Found
");
    else
        printf("Not Found
");

    return 0;
}