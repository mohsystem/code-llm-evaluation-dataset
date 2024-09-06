class Node {
    int val;
    Node left, right;

    Node(int item) {
        val = item;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    Node insert(Node node, int val) {
        if (node == null) {
            return new Node(val);
        }
        if (val < node.val) {
            node.left = insert(node.left, val);
        } else if (val > node.val) {
            node.right = insert(node.right, val);
        }
        return node;
    }

    Node minValueNode(Node node) {
        Node current = node;
        while (current.left != null) {
            current = current.left;
        }
        return current;
    }

    Node deleteNode(Node node, int val) {
        if (node == null) {
            return node;
        }
        if (val < node.val) {
            node.left = deleteNode(node.left, val);
        } else if (val > node.val) {
            node.right = deleteNode(node.right, val);
        } else {
            if (node.left == null) {
                Node temp = node.right;
                node = null;
                return temp;
            } else if (node.right == null) {
                Node temp = node.left;
                node = null;
                return temp;
            }
            Node temp = minValueNode(node.right);
            node.val = temp.val;
            node.right = deleteNode(node.right, temp.val);
        }
        return node;
    }

    Node searchNode(Node node, int val) {
        if (node == null || node.val == val) {
            return node;
        }
        if (node.val < val) {
            return searchNode(node.right, val);
        } else {
            return searchNode(node.left, val);
        }
    }

    void inorder(Node node) {
        if (node != null) {
            inorder(node.left);
            System.out.print(node.val + " ");
            inorder(node.right);
        }
    }

    public static void main(String args[]) {
        BinaryTree tree = new BinaryTree();
        tree.root = tree.insert(tree.root, 50);
        tree.root = tree.insert(tree.root, 30);
        tree.root = tree.insert(tree.root, 20);
        tree.root = tree.insert(tree.root, 40);
        tree.root = tree.insert(tree.root, 70);
        tree.root = tree.insert(tree.root, 60);
        tree.root = tree.insert(tree.root, 80);

        System.out.println("Inorder traversal of the given tree");
        tree.inorder(tree.root);

        System.out.println("\nDelete 20");
        tree.root = tree.deleteNode(tree.root, 20);
        System.out.println("Inorder traversal of the modified tree");
        tree.inorder(tree.root);

        System.out.println("\nSearch for 40");
        Node res = tree.searchNode(tree.root, 40);
        if (res != null) {
            System.out.println("Found");
        } else {
            System.out.println("Not Found");
        }
    }
}