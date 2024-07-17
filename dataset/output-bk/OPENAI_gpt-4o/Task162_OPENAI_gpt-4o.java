import java.util.Arrays;

class Graph {
    private int V;
    private int[][] graph;

    public Graph(int v) {
        V = v;
        graph = new int[V][V];
    }

    public void dijkstra(int src) {
        int[] dist = new int[V];
        boolean[] sptSet = new boolean[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        Arrays.fill(sptSet, false);
        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;
            for (int v = 0; v < V; v++)
                if (!sptSet[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }
        System.out.println(Arrays.toString(dist));
    }

    private int minDistance(int[] dist, boolean[] sptSet) {
        int min = Integer.MAX_VALUE, minIndex = -1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        return minIndex;
    }

    public void setGraph(int[][] graph) {
        this.graph = graph;
    }

    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.setGraph(new int[][]{{0, 10, 20, 0, 0}, {10, 0, 0, 50, 10}, {20, 0, 0, 20, 33}, {0, 50, 20, 0, 2}, {0, 10, 33, 2, 0}});
        g.dijkstra(0);
    }
}