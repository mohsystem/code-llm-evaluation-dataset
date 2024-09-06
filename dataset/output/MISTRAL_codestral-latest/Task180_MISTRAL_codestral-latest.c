#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node** children;
    int children_count;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->children = NULL;
    node->children_count = 0;
    return node;
}

void reparent(Node* node, Node* parent) {
    for (int i = 0; i < node->children_count; i++) {
        if (node->children[i] == parent) {
            for (int j = i; j < node->children_count - 1; j++) {
                node->children[j] = node->children[j + 1];
            }
            node->children_count--;
            node->children = (Node**)realloc(node->children, node->children_count * sizeof(Node*));
            break;
        }
    }
    for (int i = 0; i < node->children_count; i++) {
        reparent(node->children[i], node);
    }
}

void printTree(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    printf("%d\n", node->data);
    for (int i = 0; i < node->children_count; i++) {
        printTree(node->children[i], level + 1);
    }
}