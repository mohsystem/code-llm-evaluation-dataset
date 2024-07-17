
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10

typedef struct Node {
    int value;
    struct Node* children[MAX_CHILDREN];
    int childCount;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->childCount = 0;
    return node;
}

Node* findNode(Node* node, int value) {
    if (node->value == value) {
        return node;
    }
    for (int i = 0; i < node->childCount; i++) {
        Node* result = findNode(node->children[i], value);
        if (result) {
            return result;
        }
    }
    return NULL;
}

void reparentHelper(Node* node, Node* parent) {
    Node* newChildren[MAX_CHILDREN];
    int newChildCount = 0;

    for (int i = 0; i < node->childCount; i++) {
        if (node->children[i] != parent) {
            newChildren[newChildCount++] = node->children[i];
        }
    }
    if (parent) {
        newChildren[newChildCount++] = parent;
    }

    memcpy(node->children, newChildren, sizeof(Node*) * newChildCount);
    node->childCount = newChildCount;

    for (int i = 0; i < node->childCount; i++) {
        reparentHelper(node->children[i], node);
    }
}

Node* reparent(Node* root, int newRootValue) {
    Node* newRoot = findNode(root, newRootValue);
    if (!newRoot) {
        return root;
    }

    reparentHelper(newRoot, NULL);
    return newRoot;
}

void printTree(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d\
", node->value);
    for (int i = 0; i < node->childCount; i++) {
        printTree(node->children[i], level + 1);
    }
}

int main() {
    Node* root = createNode(0);
    root->children[0] = createNode(1);
    root->children[1] = createNode(2);
    root->children[2] = createNode(3);
    root->childCount = 3;

    root->children[0]->children[0] = createNode(4);
    root->children[0]->children[1] = createNode(5);
    root->children[0]->childCount = 2;

    root->children[1]->children[0] = createNode(6);
    root->children[1]->children[1] = createNode(7);
    root->children[1]->childCount = 2;

    root->children[2]->children[0] = createNode(8);
    root->children[2]->children[1] = createNode(9);
    root->children[2]->childCount = 2;

    printf("Original tree:\
");
    printTree(root, 0);

    Node* newRoot = reparent(root, 6);
    printf("\
Reparented tree with 6 as root:\
");
    printTree(newRoot, 0);

    return 0;
}
