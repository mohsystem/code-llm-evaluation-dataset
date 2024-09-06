import java.util.*;

class Node {
    int value;
    List<Node> children;

    public Node(int value) {
        this.value = value;
        this.children = new ArrayList<>();
    }
}

public class Task180_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static Node reparentTree(Node root, Node newRoot) {
        if (root == newRoot) {
            return root;
        }
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Node node = queue.poll();
            if (node == newRoot) {
                return node;
            }
            queue.addAll(node.children);
        }
        return null;
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

        System.out.println("Original tree:");
        printTree(root, 0);

        Node newRoot = reparentTree(root, new Node(6));
        System.out.println("\nReparented tree:");
        printTree(newRoot, 0);
    }
}