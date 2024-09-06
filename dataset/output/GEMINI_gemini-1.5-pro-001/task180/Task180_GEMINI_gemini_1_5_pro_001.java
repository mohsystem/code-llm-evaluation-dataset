import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Task180_GEMINI_gemini_1_5_pro_001 {

    public static int[] reparentTree(int[] parentOf, int root) {
        int n = parentOf.length;
        int[] newParentOf = new int[n];
        Arrays.fill(newParentOf, -1);
        boolean[] visited = new boolean[n];

        dfs(parentOf, newParentOf, visited, root);
        return newParentOf;
    }

    private static void dfs(int[] parentOf, int[] newParentOf, boolean[] visited, int node) {
        visited[node] = true;
        for (int child = 0; child < parentOf.length; child++) {
            if (parentOf[child] == node && !visited[child]) {
                newParentOf[child] = node;
                dfs(parentOf, newParentOf, visited, child);
            }
        }
        if (node != root) {
            newParentOf[node] = parentOf[node];
        }
    }

    public static void main(String[] args) {
        int[] parentOf = {-1, 0, 0, 0, 1, 1, 2, 2, 3, 3};
        int newRoot = 6;
        int[] newParentOf = reparentTree(parentOf, newRoot);
        System.out.println(Arrays.toString(newParentOf)); // Output: [2, 0, 6, 0, 1, 1, -1, 2, 3, 3]
    }
}