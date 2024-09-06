// Java

import java.util.*;

public class Task154_MISTRAL_codestral_latest {
    private static void dfs(Map<Character, List<Character>> graph, char node, Set<Character> visited) {
        if (!visited.contains(node)) {
            visited.add(node);
            System.out.print(node + " ");
            for (char neighbour : graph.get(node)) {
                dfs(graph, neighbour, visited);
            }
        }
    }

    public static void main(String[] args) {
        Map<Character, List<Character>> graph = new HashMap<>();
        graph.put('A', Arrays.asList('B', 'C'));
        graph.put('B', Arrays.asList('A', 'D', 'E'));
        graph.put('C', Arrays.asList('A', 'F'));
        graph.put('D', Arrays.asList('B'));
        graph.put('E', Arrays.asList('B', 'F'));
        graph.put('F', Arrays.asList('C', 'E'));

        Set<Character> visited = new HashSet<>();
        dfs(graph, 'A', visited);
    }
}