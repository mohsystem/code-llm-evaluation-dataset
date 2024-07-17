#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node** children;
    int num_children;
} Node;

Node* reparentTree(Node* root, Node* newRoot) {
    if (root == newRoot) {
        return root;
    }
    Node* parent = findParent(root, newRoot);
    if (parent) {
        for (int i = 0; i < parent->num_children; i++) {
            if (parent->children[i] == newRoot) {
                parent->children[i] = NULL;
                break;
            }
        }
        newRoot->children = (Node**) realloc(newRoot->children, (newRoot->num_children + 1) * sizeof(Node*));
        newRoot->children[newRoot->num_children] = root;
        newRoot->num_children++;
        return newRoot;
    }
    return root;
}

Node* findParent(Node* root, Node* node) {
    if (root == node) {
        return NULL;
    }
    for (int i = 0; i < root->num_children; i++) {
        Node* parent = findParent(root->children[i], node);
        if (parent) {
            return parent;
        }
    }
    return root;
}

void printTree(Node* node, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("%d
", node->value);
    for (int i = 0; i < node->num_children; i++) {
        printTree(node->children[i], level + 1);
    }
}

int main() {
    Node* root = (Node*) malloc(sizeof(Node));
    root->value = 0;
    root->children = (Node**) malloc(3 * sizeof(Node*));
    root->num_children = 3;
    root->children[0] = (Node*) malloc(sizeof(Node));
    root->children[0]->value = 1;
    root->children[0]->children = (Node**) malloc(2 * sizeof(Node*));
    root->children[0]->num_children = 2;
    root->children[0]->children[0] = (Node*) malloc(sizeof(Node));
    root->children[0]->children[0]->value = 4;
    root->children[0]->children[1] = (Node*) malloc(sizeof(Node));
    root->children[0]->children[1]->value = 5;
    root->children[1] = (Node*) malloc(sizeof(Node));
    root->children[1]->value = 2;
    root->children[1]->children = (Node**) malloc(2 * sizeof(Node*));
    root->children[1]->num_children = 2;
    root->children[1]->children[0] = (Node*) malloc(sizeof(Node));
    root->children[1]->children[0]->value = 6;
    root->children[1]->children[1] = (Node*) malloc(sizeof(Node));
    root->children[1]->children[1]->value = 7;
    root->children[2] = (Node*) malloc(sizeof(Node));
    root->children[2]->value = 3;
    root->children[2]->children = (Node**) malloc(2 * sizeof(Node*));
    root->children[2]->num_children = 2;
    root->children[2]->children[0] = (Node*) malloc(sizeof(Node));
    root->children[2]->children[0]->value = 8;
    root->children[2]->children[1] = (Node*) malloc(sizeof(Node));
    root->children[2]->children[1]->value = 9;

    Node* newRoot = root->children[1]->children[1];  // Node 6
    newRoot = reparentTree(root, newRoot);

    printTree(newRoot);

    return 0;
}