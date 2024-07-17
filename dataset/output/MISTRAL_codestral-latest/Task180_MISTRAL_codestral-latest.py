class Node:
    def __init__(self, val, children=None):
        self.val = val
        self.children = children if children is not None else []

def reparent(root, new_root_val):
    new_root = find_node(root, new_root_val)
    if new_root is None:
        return root
    parent = find_parent(root, new_root_val)
    if parent is not None:
        parent.children.remove(new_root)
    new_root.children.append(root)
    return new_root

def find_node(node, val):
    if node.val == val:
        return node
    for child in node.children:
        found = find_node(child, val)
        if found is not None:
            return found
    return None

def find_parent(node, val, parent=None):
    if node.val == val:
        return parent
    for child in node.children:
        found = find_parent(child, val, node)
        if found is not None:
            return found
    return None