import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Task153_GEMINI_gemini_1_5_pro_001 {

    public static void breadthFirstSearch(List<List<Integer>> graph, int startNode) {
        boolean[] visited = new boolean[graph.size()];
        Queue<Integer> queue = new LinkedList<>();
        visited[startNode] = true;
        queue.offer(startNode);

        while (!queue.isEmpty()) {
            int node = queue.poll();
            System.out.print(node + " ");

            for (int neighbor : graph.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.offer(neighbor);
                }
            }
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> graph = new ArrayList<>();
        // Add edges to the graph (example)
        graph.add(List.of(1, 2));
        graph.add(List.of(3, 4));
        graph.add(List.of(5));
        graph.add(List.of());
        graph.add(List.of(5));
        graph.add(List.of());

        int startNode = 0;
        breadthFirstSearch(graph, startNode);
    }
}