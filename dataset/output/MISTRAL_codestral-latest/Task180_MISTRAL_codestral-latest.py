class Node:
    def __init__(self, data):
        self.data = data
        self.children = []

def reparent(node, parent=None):
    if parent in node.children:
        node.children.remove(parent)
    node.children = [reparent(child, node) for child in node.children]
    return node

def print_tree(node, level=0):
    print(' ' * level + str(node.data))
    for child in node.children:
        print_tree(child, level + 1)