
class Node {
    int key;
    Node left, right;

    public Node(int item) {
        key = item;
        left = right = null;
    }
}

class BinarySearchTree {
    Node root;

    BinarySearchTree() {
        root = null;
    }

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    Node insertRecursive(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.key)
            root.left = insertRecursive(root.left, key);
        else if (key > root.key)
            root.right = insertRecursive(root.right, key);
        return root;
    }

    void delete(int key) {
        root = deleteRecursive(root, key);
    }

    Node deleteRecursive(Node root, int key) {
        if (root == null) return root;

        if (key < root.key)
            root.left = deleteRecursive(root.left, key);
        else if (key > root.key)
            root.right = deleteRecursive(root.right, key);
        else {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            root.key = minValue(root.right);
            root.right = deleteRecursive(root.right, root.key);
        }
        return root;
    }

    int minValue(Node root) {
        int minv = root.key;
        while (root.left != null) {
            minv = root.left.key;
            root = root.left;
        }
        return minv;
    }

    boolean search(int key) {
        return searchRecursive(root, key);
    }

    boolean searchRecursive(Node root, int key) {
        if (root == null || root.key == key)
            return root != null;
        if (key < root.key)
            return searchRecursive(root.left, key);
        return searchRecursive(root.right, key);
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);

        System.out.println("Search for 40: " + (bst.search(40) ? "Found" : "Not Found"));
        System.out.println("Search for 90: " + (bst.search(90) ? "Found" : "Not Found"));

        bst.delete(40);
        System.out.println("Search for 40 after deletion: " + (bst.search(40) ? "Found" : "Not Found"));
    }
}
