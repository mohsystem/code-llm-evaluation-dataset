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

    Node minValueNode(Node root) {
        Node current = root;
        while (current.left != null)
            current = current.left;
        return current;
    }

    Node deleteNode(Node root, int key) {
        if (root == null)
            return root;
        if (key < root.val)
            root.left = deleteNode(root.left, key);
        else if (key > root.val)
            root.right = deleteNode(root.right, key);
        else {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;
            root.val = minValueNode(root.right).val;
            root.right = deleteNode(root.right, root.val);
        }
        return root;
    }

    Node searchNode(Node root, int key) {
        if (root == null || root.val == key)
            return root;
        if (root.val < key)
            return searchNode(root.right, key);
        return searchNode(root.left, key);
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.val)
            root.left = insertRec(root.left, key);
        else if (key > root.val)
            root.right = insertRec(root.right, key);
        return root;
    }

    void inorder() {
        inorderRec(root);
    }

    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.val + " ");
            inorderRec(root.right);
        }
    }

    public static void main(String args[]) {
        BinaryTree tree = new BinaryTree();
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);

        System.out.println("Inorder traversal of the given tree");
        tree.inorder();

        System.out.println("
Delete 20");
        tree.root = tree.deleteNode(tree.root, 20);
        System.out.println("Inorder traversal of the modified tree");
        tree.inorder();

        System.out.println("
Search for 40");
        if (tree.searchNode(tree.root, 40) != null)
            System.out.println("Found");
        else
            System.out.println("Not Found");
    }
}