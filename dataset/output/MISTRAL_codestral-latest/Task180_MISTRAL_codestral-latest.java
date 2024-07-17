import java.util.ArrayList;
import java.util.List;

class Node {
    int val;
    List<Node> children;

    Node(int val) {
        this.val = val;
        this.children = new ArrayList<>();
    }
}

public class TreeReparent {
    public static Node reparent(Node root, int newRootVal) {
        Node newRoot = findNode(root, newRootVal);
        if (newRoot == null) {
            return root;
        }
        Node parent = findParent(root, newRootVal);
        if (parent != null) {
            parent.children.remove(newRoot);
        }
        newRoot.children.add(root);
        return newRoot;
    }

    private static Node findNode(Node node, int val) {
        if (node.val == val) {
            return node;
        }
        for (Node child : node.children) {
            Node found = findNode(child, val);
            if (found != null) {
                return found;
            }
        }
        return null;
    }

    private static Node findParent(Node node, int val, Node parent) {
        if (node.val == val) {
            return parent;
        }
        for (Node child : node.children) {
            Node found = findParent(child, val, node);
            if (found != null) {
                return found;
            }
        }
        return null;
    }

    private static Node findParent(Node node, int val) {
        return findParent(node, val, null);
    }
}