class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

def preorder_traversal(root):
    if root:
        print(root.data, end=" ")
        preorder_traversal(root.left)
        preorder_traversal(root.right)

def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)
        print(root.data, end=" ")
        inorder_traversal(root.right)

def postorder_traversal(root):
    if root:
        postorder_traversal(root.left)
        postorder_traversal(root.right)
        print(root.data, end=" ")

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Preorder traversal: ")
preorder_traversal(root)
print("\nInorder traversal: ")
inorder_traversal(root)
print("\nPostorder traversal: ")
postorder_traversal(root)