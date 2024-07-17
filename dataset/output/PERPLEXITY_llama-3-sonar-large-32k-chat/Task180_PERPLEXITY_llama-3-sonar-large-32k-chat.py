class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

def reparent_tree(root, new_root):
    if root == new_root:
        return root
    parent = find_parent(root, new_root)
    if parent:
        parent.children.remove(new_root)
        new_root.children.append(root)
        return new_root
    return root

def find_parent(root, node):
    if root == node:
        return None
    for child in root.children:
        parent = find_parent(child, node)
        if parent:
            return parent
    return root

# Example usage:
root = Node(0)
root.children = [Node(1), Node(2), Node(3)]
root.children[0].children = [Node(4), Node(5)]
root.children[1].children = [Node(6), Node(7)]
root.children[2].children = [Node(8), Node(9)]

new_root = root.children[1].children[1]  # Node 6
new_root = reparent_tree(root, new_root)

def print_tree(node, level=0):
    print('  ' * level + str(node.value))
    for child in node.children:
        print_tree(child, level + 1)

print_tree(new_root)