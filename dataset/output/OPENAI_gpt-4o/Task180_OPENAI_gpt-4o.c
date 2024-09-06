#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode** children;
    int childrenCount;
} TreeNode;

TreeNode* newTreeNode(int val) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->val = val;
    node->children = NULL;
    node->childrenCount = 0;
    return node;
}

TreeNode* reorientTree(TreeNode* node, TreeNode* root) {
    if (root == NULL) root = newTreeNode(node->val);
    root->children = (TreeNode**) malloc(node->childrenCount * sizeof(TreeNode*));
    root->childrenCount = node->childrenCount;
    for (int i = 0; i < node->childrenCount; i++) {
        root->children[i] = reorientTree(node->children[i], NULL);
    }
    return root;
}

void printTree(TreeNode* node, int level) {
    for (int i = 0; i < level * 2; i++) printf(" ");
    printf("%d\n", node->val);
    for (int i = 0; i < node->childrenCount; i++) {
        printTree(node->children[i], level + 1);
    }
}

int main() {
    TreeNode* n0 = newTreeNode(0);
    TreeNode* n1 = newTreeNode(1);
    TreeNode* n2 = newTreeNode(2);
    TreeNode* n3 = newTreeNode(3);
    TreeNode* n4 = newTreeNode(4);
    TreeNode* n5 = newTreeNode(5);
    TreeNode* n6 = newTreeNode(6);
    TreeNode* n7 = newTreeNode(7);
    TreeNode* n8 = newTreeNode(8);
    TreeNode* n9 = newTreeNode(9);

    n0->childrenCount = 3;
    n0->children = (TreeNode**) malloc(n0->childrenCount * sizeof(TreeNode*));
    n0->children[0] = n1;
    n0->children[1] = n2;
    n0->children[2] = n3;

    n1->childrenCount = 2;
    n1->children = (TreeNode**) malloc(n1->childrenCount * sizeof(TreeNode*));
    n1->children[0] = n4;
    n1->children[1] = n5;

    n2->childrenCount = 2;
    n2->children = (TreeNode**) malloc(n2->childrenCount * sizeof(TreeNode*));
    n2->children[0] = n6;
    n2->children[1] = n7;

    n3->childrenCount = 2;
    n3->children = (TreeNode**) malloc(n3->childrenCount * sizeof(TreeNode*));
    n3->children[0] = n8;
    n3->children[1] = n9;

    TreeNode* newRoot = reorientTree(n6, NULL);
    printTree(newRoot, 0);

    return 0;
}