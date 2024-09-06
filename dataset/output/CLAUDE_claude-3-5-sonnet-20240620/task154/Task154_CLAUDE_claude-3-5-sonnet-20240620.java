
import java.util.*;

class Graph {
    private Map<Integer, List<Integer>> graph = new HashMap<>();

    public void addEdge(int u, int v) {
        graph.putIfAbsent(u, new ArrayList<>());
        graph.get(u).add(v);
    }

    private void dfsUtil(int v, Set<Integer> visited) {
        visited.add(v);
        System.out.print(v + " ");

        for (int neighbour : graph.getOrDefault(v, new ArrayList<>())) {
            if (!visited.contains(neighbour)) {
                dfsUtil(neighbour, visited);
            }
        }
    }

    public void dfs(int v) {
        Set<Integer> visited = new HashSet<>();
        dfsUtil(v, visited);
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("Depth First Traversal (starting from vertex 2):");
        g.dfs(2);
    }
}
