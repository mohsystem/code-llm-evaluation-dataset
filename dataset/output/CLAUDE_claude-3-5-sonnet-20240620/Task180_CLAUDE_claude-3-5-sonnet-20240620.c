
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10

typedef struct Node {
    int data;
    struct Node* children[MAX_CHILDREN];
    int childCount;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->childCount = 0;
    return newNode;
}

Node* findNode(Node* node, int data) {
    if (node->data == data) {
        return node;
    }
    for (int i = 0; i < node->childCount; i++) {
        Node* result = findNode(node->children[i], data);
        if (result) {
            return result;
        }
    }
    return NULL;
}

void removeChild(Node* parent, Node* child) {
    int index = -1;
    for (int i = 0; i < parent->childCount; i++) {
        if (parent->children[i] == child) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < parent->childCount - 1; i++) {
            parent->children[i] = parent->children[i + 1];
        }
        parent->childCount--;
    }
}

void addChild(Node* parent, Node* child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    }
}

void reparentHelper(Node* node, Node* parent) {
    if (parent) {
        removeChild(node, parent);
        addChild(node, parent);
    }
    for (int i = 0; i < node->childCount; i++) {
        Node* child = node->children[i];
        if (child != parent) {
            reparentHelper(child, node);
        }
    }
}

Node* reparent(Node* root, int newRootData) {
    Node* newRoot = findNode(root, newRootData);
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
    printf("%d\\n", node->data);
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

    printf("Original tree:\\n");
    printTree(root, 0);

    Node* newRoot = reparent(root, 6);
    printf("\\nReparented tree with 6 as root:\\n");
    printTree(newRoot, 0);

    return 0;
}
