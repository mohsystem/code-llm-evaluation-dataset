import java.util.*;

public class Dijkstra {

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
            String currentNode = current.name;

            if (visited.contains(currentNode)) {
                continue;
            }

            visited.add(currentNode);

            for (Map.Entry<String, Integer> neighborEntry : graph.getOrDefault(currentNode, Collections.emptyMap()).entrySet()) {
                String neighbor = neighborEntry.getKey();
                int weight = neighborEntry.getValue();
                int distance = current.distance + weight;
                if (distance < distances.get(neighbor)) {
                    distances.put(neighbor, distance);
                    queue.offer(new Node(neighbor, distance));
                }
            }
        }

        return distances;
    }

    static class Node {
        String name;
        int distance;

        public Node(String name, int distance) {
            this.name = name;
            this.distance = distance;
        }
    }
}