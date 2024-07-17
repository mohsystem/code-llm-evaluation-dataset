import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

public class DepthFirstSearch {

    public static void depthFirstSearch(Map<Character, List<Character>> graph, char startNode) {
        Set<Character> visited = new HashSet<>();
        Stack<Character> stack = new Stack<>();
        stack.push(startNode);

        while (!stack.isEmpty()) {
            char node = stack.pop();
            if (!visited.contains(node)) {
                visited.add(node);
                System.out.print(node + " "); // Process the node here
                List<Character> neighbors = graph.getOrDefault(node, new ArrayList<>());
                for (int i = neighbors.size() - 1; i >= 0; i--) {
                    char neighbor = neighbors.get(i);
                    if (!visited.contains(neighbor)) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        // Example graph represented as an adjacency list
        Map<Character, List<Character>> graph = new HashMap<>();
        graph.put('A', List.of('B', 'C'));
        graph.put('B', List.of('D', 'E'));
        graph.put('C', List.of('F'));
        graph.put('D', new ArrayList<>());
        graph.put('E', List.of('F'));
        graph.put('F', new ArrayList<>());

        char startNode = 'A';
        depthFirstSearch(graph, startNode);
    }
}