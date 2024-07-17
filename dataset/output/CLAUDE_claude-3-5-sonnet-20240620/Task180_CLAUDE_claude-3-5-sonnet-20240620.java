
import java.util.*;

class Node {
    int value;
    List<Node> children;

    Node(int value) {
        this.value = value;
        this.children = new ArrayList<>();
    }
}

public class TreeReparenting {
    public static Node reparent(Node root, int newRootValue) {
        Node newRoot = findNode(root, newRootValue);
        if (newRoot == null) {
            return root;
        }

        reparentHelper(newRoot, null);
        return newRoot;
    }

    private static Node findNode(Node node, int value) {
        if (node.value == value) {
            return node;
        }
        for (Node child : node.children) {
            Node result = findNode(child, value);
            if (result != null) {
                return result;
            }
        }
        return null;
    }

    private static void reparentHelper(Node node, Node parent) {
        List<Node> newChildren = new ArrayList<>();
        for (Node child : node.children) {
            if (child != parent) {
                newChildren.add(child);
            }
        }
        if (parent != null) {
            newChildren.add(parent);
        }
        node.children = newChildren;
        for (Node child : node.children) {
            reparentHelper(child, node);
        }
    }

    public static void printTree(Node node, int level) {
        System.out.println("  ".repeat(level) + node.value);
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
        System.out.println("\
Reparented tree with 6 as root:");
        printTree(newRoot, 0);
    }
}
