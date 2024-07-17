import java.util.*;

public class DepthFirstSearch {
    private static void dfs(Map<String, List<String>> graph, String node, Set<String> visited) {
        if (!visited.contains(node)) {
            visited.add(node);
            for (String n : graph.get(node)) {
                dfs(graph, n, visited);
            }
        }
    }

    public static void main(String[] args) {
        Map<String, List<String>> graph = new HashMap<>();
        graph.put("A", Arrays.asList("B", "C"));
        graph.put("B", Arrays.asList("A", "D", "E"));
        graph.put("C", Arrays.asList("A", "F"));
        graph.put("D", Arrays.asList("B"));
        graph.put("E", Arrays.asList("B", "F"));
        graph.put("F", Arrays.asList("C", "E"));

        Set<String> visited = new HashSet<>();
        dfs(graph, "A", visited);
        System.out.println(visited);
    }
}