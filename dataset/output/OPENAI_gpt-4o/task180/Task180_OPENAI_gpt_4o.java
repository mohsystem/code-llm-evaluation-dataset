import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    List<TreeNode> children;

    public TreeNode(int val) {
        this.val = val;
        this.children = new ArrayList<>();
    }
}

public class Task180_OPENAI_gpt_4o {

    public static TreeNode reorientTree(TreeNode node, TreeNode root) {
        if (root == null) root = new TreeNode(node.val);
        for (TreeNode child : node.children) {
            TreeNode childNode = new TreeNode(child.val);
            root.children.add(childNode);
            reorientTree(child, childNode);
        }
        return root;
    }

    public static void printTree(TreeNode node, int level) {
        for (int i = 0; i < level * 2; i++) System.out.print(" ");
        System.out.println(node.val);
        for (TreeNode child : node.children) {
            printTree(child, level + 1);
        }
    }

    public static void main(String[] args) {
        TreeNode n0 = new TreeNode(0);
        TreeNode n1 = new TreeNode(1);
        TreeNode n2 = new TreeNode(2);
        TreeNode n3 = new TreeNode(3);
        TreeNode n4 = new TreeNode(4);
        TreeNode n5 = new TreeNode(5);
        TreeNode n6 = new TreeNode(6);
        TreeNode n7 = new TreeNode(7);
        TreeNode n8 = new TreeNode(8);
        TreeNode n9 = new TreeNode(9);

        n0.children.add(n1);
        n0.children.add(n2);
        n0.children.add(n3);
        n1.children.add(n4);
        n1.children.add(n5);
        n2.children.add(n6);
        n2.children.add(n7);
        n3.children.add(n8);
        n3.children.add(n9);

        TreeNode newRoot = reorientTree(n6, null);
        printTree(newRoot, 0);
    }
}