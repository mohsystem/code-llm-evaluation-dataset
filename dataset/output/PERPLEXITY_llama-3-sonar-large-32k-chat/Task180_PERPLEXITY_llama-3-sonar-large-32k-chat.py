class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

def reparent_tree(root, new_root):
    if root == new_root:
        return root
    queue = [root]
    while queue:
        node = queue.pop(0)
        if node == new_root:
            return node
        queue.extend(node.children)
    return None

def print_tree(node, level=0):
    print('  ' * level + str(node.value))
    for child in node.children:
        print_tree(child, level + 1)

# Example usage
root = Node(0)
root.children = [Node(1), Node(2), Node(3)]
root.children[0].children = [Node(4), Node(5)]
root.children[1].children = [Node(6), Node(7)]
root.children[2].children = [Node(8), Node(9)]

print("Original tree:")
print_tree(root)

new_root = reparent_tree(root, Node(6))
print("\nReparented tree:")
print_tree(new_root)