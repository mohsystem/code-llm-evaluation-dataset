import java.util.*;

public class DijkstraAlgorithm {
    private static final int INFINITY = Integer.MAX_VALUE;

    public static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String start) {
        Map<String, Integer> distances = new HashMap<>();
        PriorityQueue<Node> priorityQueue = new PriorityQueue<>();

        for (String node : graph.keySet()) {
            if (node.equals(start)) {
                distances.put(node, 0);
                priorityQueue.add(new Node(node, 0));
            } else {
                distances.put(node, INFINITY);
                priorityQueue.add(new Node(node, INFINITY));
            }
        }

        while (!priorityQueue.isEmpty()) {
            Node currentNode = priorityQueue.poll();
            String currentNodeName = currentNode.getName();

            if (currentNode.getDistance() > distances.get(currentNodeName)) {
                continue;
            }

            Map<String, Integer> neighbors = graph.get(currentNodeName);
            for (String neighbor : neighbors.keySet()) {
                int distance = distances.get(currentNodeName) + neighbors.get(neighbor);

                if (distance < distances.get(neighbor)) {
                    distances.put(neighbor, distance);
                    priorityQueue.add(new Node(neighbor, distance));
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        Map<String, Map<String, Integer>> graph = new HashMap<>();
        graph.put("A", new HashMap<>());
        graph.get("A").put("B", 1);
        graph.get("A").put("C", 4);
        graph.put("B", new HashMap<>());
        graph.get("B").put("A", 1);
        graph.get("B").put("C", 2);
        graph.get("B").put("D", 5);
        graph.put("C", new HashMap<>());
        graph.get("C").put("A", 4);
        graph.get("C").put("B", 2);
        graph.get("C").put("D", 1);
        graph.put("D", new HashMap<>());
        graph.get("D").put("B", 5);
        graph.get("D").put("C", 1);

        String startNode = "A";
        Map<String, Integer> shortestPaths = dijkstra(graph, startNode);
        System.out.println(shortestPaths);
    }
}

class Node implements Comparable<Node> {
    private String name;
    private int distance;

    public Node(String name, int distance) {
        this.name = name;
        this.distance = distance;
    }

    public String getName() {
        return name;
    }

    public int getDistance() {
        return distance;
    }

    @Override
    public int compareTo(Node other) {
        return Integer.compare(this.distance, other.distance);
    }
}