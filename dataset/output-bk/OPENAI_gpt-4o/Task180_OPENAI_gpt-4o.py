class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

def build_tree(edges):
    nodes = {}
    for parent, child in edges:
        if parent not in nodes:
            nodes[parent] = TreeNode(parent)
        if child not in nodes:
            nodes[child] = TreeNode(child)
        nodes[parent].children.append(nodes[child])
    return nodes

def reorient_tree(node, parent=None):
    if parent:
        node.children.remove(parent)
        node.children.append(parent)
    for child in list(node.children):
        reorient_tree(child, node)
    return node

# Example usage:
edges = [(0, 1), (0, 2), (0, 3), (1, 4), (1, 5), (2, 6), (2, 7), (3, 8), (3, 9)]
nodes = build_tree(edges)
new_root = reorient_tree(nodes[6])

from collections import deque

def print_tree(root):
    q = deque([(root, 0)])
    while q:
        node, level = q.pop()
        print("  " * level + str(node.value))
        for child in node.children:
            q.appendleft((child, level + 1))

print_tree(new_root)