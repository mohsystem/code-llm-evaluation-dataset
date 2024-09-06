import java.util.*;

class Main {
    static class Node implements Comparable<Node> {
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

    static Map<String, Map<String, Integer>> graph = new HashMap<>();
    static {
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
    }

    public static void main(String[] args) {
        String startNode = "A";
        Map<String, Integer> distances = dijkstra(graph, startNode);
        System.out.println(distances);
    }

    static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String start) {
        Map<String, Integer> distances = new HashMap<>();
        for (String node : graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);

        PriorityQueue<Node> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(new Node(start, 0));

        while (!priorityQueue.isEmpty()) {
            Node currentNode = priorityQueue.poll();

            if (currentNode.distance > distances.get(currentNode.name)) {
                continue;
            }

            for (Map.Entry<String, Integer> neighbor : graph.get(currentNode.name).entrySet()) {
                int distance = currentNode.distance + neighbor.getValue();

                if (distance < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), distance);
                    priorityQueue.add(new Node(neighbor.getKey(), distance));
                }
            }
        }

        return distances;
    }
}