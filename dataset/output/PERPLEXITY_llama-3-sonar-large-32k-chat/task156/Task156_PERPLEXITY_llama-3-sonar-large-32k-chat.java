class Node {
    int data;
    Node left, right;

    Node(int item) {
        data = item;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    void preorder_traversal(Node node) {
        if (node == null)
            return;
        System.out.print(node.data + " ");
        preorder_traversal(node.left);
        preorder_traversal(node.right);
    }

    void inorder_traversal(Node node) {
        if (node == null)
            return;
        inorder_traversal(node.left);
        System.out.print(node.data + " ");
        inorder_traversal(node.right);
    }

    void postorder_traversal(Node node) {
        if (node == null)
            return;
        postorder_traversal(node.left);
        postorder_traversal(node.right);
        System.out.print(node.data + " ");
    }

    public static void main(String args[]) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.print("Preorder traversal: ");
        tree.preorder_traversal(tree.root);
        System.out.print("\nInorder traversal: ");
        tree.inorder_traversal(tree.root);
        System.out.print("\nPostorder traversal: ");
        tree.postorder_traversal(tree.root);
    }
}