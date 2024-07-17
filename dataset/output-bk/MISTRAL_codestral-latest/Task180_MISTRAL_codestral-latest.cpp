#include <vector>
#include <memory>

struct Node {
    int val;
    std::vector<std::shared_ptr<Node>> children;

    Node(int val) : val(val) {}
};

std::shared_ptr<Node> reparent(std::shared_ptr<Node> root, int newRootVal) {
    std::shared_ptr<Node> newRoot = findNode(root, newRootVal);
    if (newRoot == nullptr) {
        return root;
    }
    std::shared_ptr<Node> parent = findParent(root, newRootVal);
    if (parent != nullptr) {
        parent->children.erase(std::remove(parent->children.begin(), parent->children.end(), newRoot), parent->children.end());
    }
    newRoot->children.push_back(root);
    return newRoot;
}

std::shared_ptr<Node> findNode(std::shared_ptr<Node> node, int val) {
    if (node->val == val) {
        return node;
    }
    for (const auto& child : node->children) {
        std::shared_ptr<Node> found = findNode(child, val);
        if (found != nullptr) {
            return found;
        }
    }
    return nullptr;
}

std::shared_ptr<Node> findParent(std::shared_ptr<Node> node, int val, std::shared_ptr<Node> parent = nullptr) {
    if (node->val == val) {
        return parent;
    }
    for (const auto& child : node->children) {
        std::shared_ptr<Node> found = findParent(child, val, node);
        if (found != nullptr) {
            return found;
        }
    }
    return nullptr;
}