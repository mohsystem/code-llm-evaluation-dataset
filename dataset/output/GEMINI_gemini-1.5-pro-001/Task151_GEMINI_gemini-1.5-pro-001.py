class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, curr_node):
        if data < curr_node.data:
            if curr_node.left is None:
                curr_node.left = Node(data)
            else:
                self._insert(data, curr_node.left)
        elif data > curr_node.data:
            if curr_node.right is None:
                curr_node.right = Node(data)
            else:
                self._insert(data, curr_node.right)
        else:
            print("Value already exists in tree.")

    def search(self, data):
        if self.root is None:
            return None
        else:
            return self._search(data, self.root)

    def _search(self, data, curr_node):
        if data == curr_node.data:
            return curr_node
        elif data < curr_node.data:
            if curr_node.left is None:
                return None
            else:
                return self._search(data, curr_node.left)
        else:
            if curr_node.right is None:
                return None
            else:
                return self._search(data, curr_node.right)

    def delete(self, data):
        if self.root is None:
            return
        else:
            self._delete(data, self.root, None)

    def _delete(self, data, curr_node, parent):
        if data < curr_node.data:
            if curr_node.left is None:
                return
            else:
                self._delete(data, curr_node.left, curr_node)
        elif data > curr_node.data:
            if curr_node.right is None:
                return
            else:
                self._delete(data, curr_node.right, curr_node)
        else:
            if curr_node.left is None:
                if parent is None:
                    self.root = curr_node.right
                else:
                    if parent.left == curr_node:
                        parent.left = curr_node.right
                    else:
                        parent.right = curr_node.right
                return
            else:
                pred = self._get_predecessor(curr_node.left)
                curr_node.data = pred.data
                self._delete(pred.data, pred, curr_node)

    def _get_predecessor(self, curr_node):
        if curr_node.right is None:
            return curr_node
        else:
            return self._get_predecessor(curr_node.right)

    def print_tree(self):
        if self.root is None:
            print("Tree is empty.")
        else:
            self._print_tree(self.root)

    def _print_tree(self, curr_node):
        if curr_node is None:
            return
        else:
            self._print_tree(curr_node.left)
            print(curr_node.data)
            self._print_tree(curr_node.right)


if __name__ == "__main__":
    bst = BinarySearchTree()
    bst.insert(10)
    bst.insert(5)
    bst.insert(15)
    bst.insert(2)
    bst.insert(7)
    bst.insert(12)
    bst.insert(20)
    bst.print_tree()
    print("Searching for 15:", bst.search(15))
    print("Deleting 15:")
    bst.delete(15)
    bst.print_tree()