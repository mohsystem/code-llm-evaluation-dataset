import java.util.*;

class TreeNode {
    int value;
    List<TreeNode> children = new ArrayList<>();

    TreeNode(int value) {
        this.value = value;
    }
}

public class ReorientTree {

    public static TreeNode buildTree(int[][] edges) {
        Map<Integer, TreeNode> nodes = new HashMap<>();
        for (int[] edge : edges) {
            int parent = edge[0], child = edge[1];
            nodes.putIfAbsent(parent, new TreeNode(parent));
            nodes.putIfAbsent(child, new TreeNode(child));
            nodes.get(parent).children.add(nodes.get(child));
        }
        return nodes.isEmpty() ? null : nodes.values().iterator().next();
    }

    public static TreeNode reorientTree(TreeNode node, TreeNode parent) {
        if (parent != null) {
            node.children.remove(parent);
            node.children.add(parent);
        }
        for (TreeNode child : new ArrayList<>(node.children)) {
            reorientTree(child, node);
        }
        return node;
    }

    public static void printTree(TreeNode root, int level) {
        if (root == null) return;
        System.out.println("  ".repeat(level) + root.value);
        for (TreeNode child : root.children) {
            printTree(child, level + 1);
        }
    }

    public static void main(String[] args) {
        int[][] edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {2, 7}, {3, 8}, {3, 9}};
        TreeNode root = buildTree(edges);
        reorientTree(root, null);
        TreeNode newRoot = reorientTree(root.children.get(1).children.get(0), null); // reorienting at node 6
        printTree(newRoot, 0);
    }
}