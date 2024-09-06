#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    vector<TreeNode*> children;

    TreeNode(int val) {
        this->val = val;
    }
};

TreeNode* reorientTree(TreeNode* node) {
    TreeNode* root = new TreeNode(node->val);
    for (TreeNode* child : node->children) {
        TreeNode* childNode = reorientTree(child);
        root->children.push_back(childNode);
    }
    return root;
}

void printTree(TreeNode* node, int level = 0) {
    for (int i = 0; i < level * 2; i++) cout << " ";
    cout << node->val << endl;
    for (TreeNode* child : node->children) {
        printTree(child, level + 1);
    }
}

int main() {
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n9 = new TreeNode(9);

    n0->children.push_back(n1);
    n0->children.push_back(n2);
    n0->children.push_back(n3);
    n1->children.push_back(n4);
    n1->children.push_back(n5);
    n2->children.push_back(n6);
    n2->children.push_back(n7);
    n3->children.push_back(n8);
    n3->children.push_back(n9);

    TreeNode* newRoot = reorientTree(n6);
    printTree(newRoot);

    return 0;
}