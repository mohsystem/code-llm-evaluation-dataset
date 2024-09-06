#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* node, int val) {
    if (node == NULL) {
        return (Node*)malloc(sizeof(Node));
        node->val = val;
        node->left = node->right = NULL;
    } else {
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else if (val > node->val) {
            node->right = insert(node->right, val);
        }
    }
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* node, int val) {
    if (node == NULL) {
        return node;
    }
    if (val < node->val) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->val) {
        node->right = deleteNode(node->right, val);
    } else {
        if (node->left == NULL) {
            Node* temp = node->right;
            node = NULL;
            return temp;
        } else if (node->right == NULL) {
            Node* temp = node->left;
            node = NULL;
            return temp;
        }
        Node* temp = minValueNode(node->right);
        node->val = temp->val;
        node->right = deleteNode(node->right, temp->val);
    }
    return node;
}

Node* searchNode(Node* node, int val) {
    if (node == NULL || node->val == val) {
        return node;
    }
    if (node->val < val) {
        return searchNode(node->right, val);
    } else {
        return searchNode(node->left, val);
    }
}

void inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->val);
        inorder(node->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree\n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree\n");
    inorder(root);

    printf("\nSearch for 40\n");
    Node* res = searchNode(root, 40);
    if (res != NULL) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}