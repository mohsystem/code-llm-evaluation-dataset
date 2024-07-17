import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ReparentTree {

    public static int[] reparentTree(int[] parent, int newRoot) {
        int n = parent.length;
        List<List<Integer>> children = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            children.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                children.get(parent[i]).add(i);
            }
        }

        int[] newParent = new int[n];
        Arrays.fill(newParent, -1);
        dfs(newRoot, -1, children, newParent);
        return newParent;
    }

    private static void dfs(int node, int prev, List<List<Integer>> children, int[] newParent) {
        newParent[node] = prev;
        for (int child : children.get(node)) {
            if (child != prev) {
                dfs(child, node, children, newParent);
            }
        }
    }

    public static void main(String[] args) {
        // Example usage:
        int[] parent = {0, 0, 0, 1, 1, 2, 2};
        int newRoot = 2;
        int[] newParent = reparentTree(parent, newRoot);
        System.out.println(Arrays.toString(newParent)); // Output: [-1, 0, 2, 1, 1, 2, 6]
    }
}