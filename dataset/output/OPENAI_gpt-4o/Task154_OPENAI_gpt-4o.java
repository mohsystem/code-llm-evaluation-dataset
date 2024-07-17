import java.util.*;

public class Combined {
    // Entry point for combined languages
    public static void main(String[] args) {
        Combined combined = new Combined();
        combined.javaDFS();
    }

    // Java part
    void javaDFS() {
        Map<Character, List<Character>> graph = new HashMap<>();
        graph.put('A', Arrays.asList('B', 'C'));
        graph.put('B', Arrays.asList('D', 'E'));
        graph.put('C', Arrays.asList('F'));
        graph.put('D', new ArrayList<>());
        graph.put('E', new ArrayList<>());
        graph.put('F', new ArrayList<>());

        Set<Character> visited = new HashSet<>();
        depthFirstSearch(graph, 'A', visited);
    }

    void depthFirstSearch(Map<Character, List<Character>> graph, char node, Set<Character> visited) {
        if (!visited.contains(node)) {
            System.out.println(node);
            visited.add(node);
            for (char neighbour : graph.get(node)) {
                depthFirstSearch(graph, neighbour, visited);
            }
        }
    }
}