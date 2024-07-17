
import java.util.*;

public class DijkstraAlgorithm {
    private static class Node implements Comparable<Node> {
        String name;
        int distance;

        Node(String name, int distance) {
            this.name = name;
            this.distance = distance;
        }

        @Override
        public int compareTo(Node other) {
            return Integer.compare(this.distance, other.distance);
        }
    }

    public static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String start) {
        Map<String, Integer> distances = new HashMap<>();
        for (String node : graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));

        while (!pq.isEmpty()) {
            Node current = pq.poll();
            String currentNode = current.name;
            int currentDistance = current.distance;

            if (currentDistance > distances.get(currentNode)) {
                continue;
            }

            for (Map.Entry<String, Integer> neighbor : graph.get(currentNode).entrySet()) {
                String neighborNode = neighbor.getKey();
                int weight = neighbor.getValue();
                int distance = currentDistance + weight;

                if (distance < distances.get(neighborNode)) {
                    distances.put(neighborNode, distance);
                    pq.offer(new Node(neighborNode, distance));
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", new HashMap<>());
        graph.get("A").put("B", 4);
        graph.get("A").put("C", 2);
        graph.put("B", new HashMap<>());
        graph.get("B").put("D", 3);
        graph.get("B").put("E", 1);
        graph.put("C", new HashMap<>());
        graph.get("C").put("B", 1);
        graph.get("C").put("D", 5);
        graph.put("D", new HashMap<>());
        graph.get("D").put("E", 2);
        graph.put("E", new HashMap<>());

        String startNode = "A";
        Map<String, Integer> shortestPaths = dijkstra(graph, startNode);

        System.out.println("Shortest paths from " + startNode);
        for (Map.Entry<String, Integer> entry : shortestPaths.entrySet()) {
            System.out.println("To " + entry.getKey() + ": " + entry.getValue());
        }
    }
}
