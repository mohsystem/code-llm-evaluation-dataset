import java.util.*;

class Graph {
    private int numNodes;
    private List<List<Integer>> adjList;
    private boolean[] visited;

    public Graph(int numNodes) {
        this.numNodes = numNodes;
        this.adjList = new ArrayList<>();
        for (int i = 0; i < numNodes; i++) {
            this.adjList.add(new ArrayList<>());
        }
        this.visited = new boolean[numNodes];
    }

    public void addEdge(int u, int v) {
        this.adjList.get(u).add(v);
    }

    public void bfs(int startNode) {
        Queue<Integer> queue = new LinkedList<>();

        queue.add(startNode);
        this.visited[startNode] = true;

        while (!queue.isEmpty()) {
            int node = queue.poll();
            System.out.print(node + " ");

            for (int neighbor : this.adjList.get(node)) {
                if (!this.visited[neighbor]) {
                    queue.add(neighbor);
                    this.visited[neighbor] = true;
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 4);

        System.out.println("BFS traversal starting from node 0:");
        g.bfs(0);
    }
}