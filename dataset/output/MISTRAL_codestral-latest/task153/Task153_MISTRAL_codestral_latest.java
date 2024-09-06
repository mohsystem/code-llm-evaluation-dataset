import java.util.*;

public class Task153_MISTRAL_codestral_latest {
    private static void bfs(Map<Character, List<Character>> graph, Character start) {
        Set<Character> visited = new HashSet<>();
        Queue<Character> queue = new LinkedList<>();

        queue.add(start);
        visited.add(start);

        while (!queue.isEmpty()) {
            Character node = queue.poll();
            System.out.print(node + " ");

            for (Character neighbor : graph.get(node)) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(neighbor);
                }
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

        bfs(graph, 'A');
    }
}