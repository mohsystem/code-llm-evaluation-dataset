import java.util.ArrayList;
import java.util.List;

class Node {
    int value;
    List<Node> children;

    public Node(int value) {
        this.value = value;
        this.children = new ArrayList<>();
    }
}

public class Main {
    public static Node reparentTree(Node root, Node newRoot) {
        if (root == newRoot) {
            return root;
        }
        Node parent = findParent(root, newRoot);
        if (parent != null) {
            parent.children.remove(newRoot);
            newRoot.children.add(root);
            return newRoot;
        }
        return root;
    }

    public static Node findParent(Node root, Node node) {
        if (root == node) {
            return null;
        }
        for (Node child : root.children) {
            Node parent = findParent(child, node);
            if (parent != null) {
                return parent;
            }
        }
        return root;
    }

    public static void printTree(Node node, int level) {
        for (int i = 0; i < level; i++) {
            System.out.print("  ");
        }
        System.out.println(node.value);
        for (Node child : node.children) {
            printTree(child, level + 1);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(0);
        root.children.add(new Node(1));
        root.children.add(new Node(2));
        root.children.add(new Node(3));
        root.children.get(0).children.add(new Node(4));
        root.children.get(0).children.add(new Node(5));
        root.children.get(1).children.add(new Node(6));
        root.children.get(1).children.add(new Node(7));
        root.children.get(2).children.add(new Node(8));
        root.children.get(2).children.add(new Node(9));

        Node newRoot = root.children.get(1).children.get(1);  // Node 6
        newRoot = reparentTree(root, newRoot);

        printTree(newRoot);
    }
}