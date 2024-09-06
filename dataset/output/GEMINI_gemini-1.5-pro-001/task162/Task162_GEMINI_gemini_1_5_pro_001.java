import java.util.*;

public class Task162_GEMINI_gemini_1_5_pro_001 {

    public static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String start) {
        Map<String, Integer> distances = new HashMap<>();
        for (String node : graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);

        PriorityQueue<Node> queue = new PriorityQueue<>(Comparator.comparingInt(n -> n.distance));
        queue.offer(new Node(start, 0));
        Set<String> visited = new HashSet<>();

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            String currentNode = current.vertex;

            if (visited.contains(currentNode)) {
                continue;
            }
            visited.add(currentNode);

            for (Map.Entry<String, Integer> neighborEntry : graph.get(currentNode).entrySet()) {
                String neighbor = neighborEntry.getKey();
                int weight = neighborEntry.getValue();
                int distance = distances.get(currentNode) + weight;
                if (distance < distances.get(neighbor)) {
                    distances.put(neighbor, distance);
                    queue.offer(new Node(neighbor, distance));
                }
            }
        }
        return distances;
    }

    static class Node {
        String vertex;
        int distance;

        Node(String vertex, int distance) {
            this.vertex = vertex;
            this.distance = distance;
        }
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", new HashMap<>(Map.of("B", 1, "C", 4)));
        graph.put("B", new HashMap<>(Map.of("A", 1, "C", 2, "D", 5)));
        graph.put("C", new HashMap<>(Map.of("A", 4, "B", 2, "D", 1)));
        graph.put("D", new HashMap<>(Map.of("B", 5, "C", 1)));

        String startNode = "A";
        Map<String, Integer> distances = dijkstra(graph, startNode);

        System.out.println("Shortest distances from node " + startNode + ": " + distances);
    }
}