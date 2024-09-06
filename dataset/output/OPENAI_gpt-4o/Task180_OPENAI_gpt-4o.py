class TreeNode:
    def __init__(self, val):
        self.val = val
        self.children = []

def reorient_tree(node, root=None):
    if root is None:
        root = TreeNode(node.val)
    for child in node.children:
        child_node = TreeNode(child.val)
        root.children.append(child_node)
        reorient_tree(child, child_node)
    return root

def print_tree(node, level=0):
    print(" " * (level * 2) + str(node.val))
    for child in node.children:
        print_tree(child, level + 1)

# Example tree
n0 = TreeNode(0)
n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n4 = TreeNode(4)
n5 = TreeNode(5)
n6 = TreeNode(6)
n7 = TreeNode(7)
n8 = TreeNode(8)
n9 = TreeNode(9)

n0.children = [n1, n2, n3]
n1.children = [n4, n5]
n2.children = [n6, n7]
n3.children = [n8, n9]

# Reorient tree
new_root = reorient_tree(n6)

# Print reoriented tree
print_tree(new_root)