
import java.util.*;

class Node {
    int data;
    List<Node> children;

    Node(int data) {
        this.data = data;
        this.children = new ArrayList<>();
    }
}

public class Task180_CLAUDE_claude_3_5_sonnet_20240620 {
    public static Node reparent(Node root, int newRootData) {
        Node newRoot = findNode(root, newRootData);
        if (newRoot == null) {
            return root;
        }

        reparentHelper(newRoot, null);
        return newRoot;
    }

    private static Node findNode(Node node, int data) {
        if (node.data == data) {
            return node;
        }
        for (Node child : node.children) {
            Node result = findNode(child, data);
            if (result != null) {
                return result;
            }
        }
        return null;
    }

    private static void reparentHelper(Node node, Node parent) {
        if (parent != null) {
            node.children.remove(parent);
            node.children.add(parent);
        }
        for (Node child : new ArrayList<>(node.children)) {
            if (child != parent) {
                reparentHelper(child, node);
            }
        }
    }

    public static void printTree(Node node, int level) {
        System.out.println("  ".repeat(level) + node.data);
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

        System.out.println("Original tree:");
        printTree(root, 0);

        Node newRoot = reparent(root, 6);
        System.out.println("\\nReparented tree with 6 as root:");
        printTree(newRoot, 0);
    }
}
