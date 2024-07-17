
class Node:
    def __init__(self, value):
        self.value = value
        self.children = []

def reparent(root, new_root_value):
    def find_node(node, value):
        if node.value == value:
            return node
        for child in node.children:
            result = find_node(child, value)
            if result:
                return result
        return None

    def reparent_helper(node, parent):
        new_children = []
        for child in node.children:
            if child != parent:
                new_children.append(child)
        if parent:
            new_children.append(parent)
        node.children = new_children
        for child in node.children:
            reparent_helper(child, node)

    new_root = find_node(root, new_root_value)
    if not new_root:
        return root

    reparent_helper(new_root, None)
    return new_root

def print_tree(node, level=0):
    print("  " * level + str(node.value))
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

new_root = reparent(root, 6)
print("\
Reparented tree with 6 as root:")
print_tree(new_root)
