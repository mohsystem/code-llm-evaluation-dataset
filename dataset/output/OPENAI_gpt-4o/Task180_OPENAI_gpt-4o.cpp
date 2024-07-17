#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class TreeNode {
public:
    int value;
    std::vector<TreeNode*> children;

    TreeNode(int val) : value(val) {}
};

std::unordered_map<int, TreeNode*> buildTree(const std::vector<std::pair<int, int>>& edges) {
    std::unordered_map<int, TreeNode*> nodes;
    for (const auto& edge : edges) {
        int parent = edge.first, child = edge.second;
        if (nodes.find(parent) == nodes.end()) nodes[parent] = new TreeNode(parent);
        if (nodes.find(child) == nodes.end()) nodes[child] = new TreeNode(child);
        nodes[parent]->children.push_back(nodes[child]);
    }
    return nodes;
}

void reorientTree(TreeNode* node, TreeNode* parent) {
    if (parent) {
        auto it = std::remove(node->children.begin(), node->children.end(), parent);
        node->children.erase(it, node->children.end());
        node->children.push_back(parent);
    }
    for (auto child : node->children) {
        reorientTree(child, node);
    }
}

void printTree(TreeNode* root, int level) {
    if (!root) return;
    std::cout << std::string(level * 2, ' ') << root->value << std::endl;
    for (auto child : root->children) {
        printTree(child, level + 1);
    }
}

int main() {
    std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {3, 8}, {3, 9}};
    auto nodes = buildTree(edges);
    auto root = nodes[0];
    reorientTree(root, nullptr);
    auto newRoot = nodes[6];
    reorientTree(newRoot, nullptr);
    printTree(newRoot, 0);
    return 0;
}