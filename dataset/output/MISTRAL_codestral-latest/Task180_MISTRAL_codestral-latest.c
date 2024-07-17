#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int val;
    struct Node** children;
    int children_count;
} Node;

Node* reparent(Node* root, int newRootVal) {
    Node* newRoot = findNode(root, newRootVal);
    if (newRoot == NULL) {
        return root;
    }
    Node* parent = findParent(root, newRootVal);
    if (parent != NULL) {
        for (int i = 0; i < parent->children_count; i++) {
            if (parent->children[i] == newRoot) {
                for (int j = i; j < parent->children_count - 1; j++) {
                    parent->children[j] = parent->children[j + 1];
                }
                parent->children_count--;
                break;
            }
        }
    }
    newRoot->children = realloc(newRoot->children, (newRoot->children_count + 1) * sizeof(Node*));
    newRoot->children[newRoot->children_count++] = root;
    return newRoot;
}

Node* findNode(Node* node, int val) {
    if (node->val == val) {
        return node;
    }
    for (int i = 0; i < node->children_count; i++) {
        Node* found = findNode(node->children[i], val);
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

Node* findParent(Node* node, int val, Node* parent) {
    if (node->val == val) {
        return parent;
    }
    for (int i = 0; i < node->children_count; i++) {
        Node* found = findParent(node->children[i], val, node);
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

Node* findParentWrapper(Node* node, int val) {
    return findParent(node, val, NULL);
}