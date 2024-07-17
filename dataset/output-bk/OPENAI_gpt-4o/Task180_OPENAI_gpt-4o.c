#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode** children;
    int children_size;
};

struct TreeNode* create_node(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->children = NULL;
    node->children_size = 0;
    return node;
}

void add_child(struct TreeNode* parent, struct TreeNode* child) {
    parent->children_size++;
    parent->children = (struct TreeNode**)realloc(parent->children, parent->children_size * sizeof(struct TreeNode*));
    parent->children[parent->children_size - 1] = child;
}

struct TreeNode** build_tree(int edges[][2], int edges_size) {
    struct TreeNode** nodes = (struct TreeNode**)calloc(10, sizeof(struct TreeNode*)); // Assume max 10 nodes for simplicity
    for (int i = 0; i < edges_size; i++) {
        int parent = edges[i][0], child = edges[i][1];
        if (nodes[parent] == NULL) nodes[parent] = create_node(parent);
        if (nodes[child] == NULL) nodes[child] = create_node(child);
        add_child(nodes[parent], nodes[child]);
    }
    return nodes;
}

void reorient_tree(struct TreeNode* node, struct TreeNode* parent) {
    if (parent) {
        for (int i = 0; i < node->children_size; i++) {
            if (node->children[i] == parent) {
                node->children[i] = node->children[node->children_size - 1];
                node->children_size--;
                node->children = (struct TreeNode**)realloc(node->children, node->children_size * sizeof(struct TreeNode*));
                break;
            }
        }
        add_child(node, parent);
    }
    for (int i = 0; i < node->children_size; i++) {
        reorient_tree(node->children[i], node);
    }
}

void print_tree(struct TreeNode* root, int level) {
    if (!root) return;
    printf("%*s%d
", level * 2, "", root->value);
    for (int i = 0; i < root->children_size; i++) {
        print_tree(root->children[i], level + 1);
    }
}

int main() {
    int edges[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {3, 8}, {3, 9}};
    int edges_size = sizeof(edges) / sizeof(edges[0]);
    struct TreeNode** nodes = build_tree(edges, edges_size);
    reorient_tree(nodes[0], NULL);
    struct TreeNode* new_root = nodes[6];
    reorient_tree(new_root, NULL);
    print_tree(new_root, 0);
    return 0;
}