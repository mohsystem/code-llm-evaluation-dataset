import java.util.*;

class Main {
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
        Map<String, Integer> distances = dijkstra(graph, startNode);
        System.out.println(distances);
    }

    public static Map<String, Integer> dijkstra(Map<String, Map<String, Integer>> graph, String start) {
        Map<String, Integer> distances = new HashMap<>();
        for (String node : graph.keySet()) {
            distances.put(node, Integer.MAX_VALUE);
        }
        distances.put(start, 0);
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        pq.add(new AbstractMap.SimpleEntry<>(start, 0));
        while (!pq.isEmpty()) {
            Map.Entry<String, Integer> current = pq.poll();
            for (Map.Entry<String, Integer> neighbor : graph.get(current.getKey()).entrySet()) {
                if (current.getValue() + neighbor.getValue() < distances.get(neighbor.getKey())) {
                    distances.put(neighbor.getKey(), current.getValue() + neighbor.getValue());
                    pq.add(new AbstractMap.SimpleEntry<>(neighbor.getKey(), distances.get(neighbor.getKey())));
                }
            }
        }
        return distances;
    }
}