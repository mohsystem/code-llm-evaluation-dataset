code here:
#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    Graph(int numNodes) : numNodes(numNodes), adjList(numNodes) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void dfs(int startNode) {
        std::vector<bool> visited(numNodes, false);
        dfsHelper(startNode, visited);
    }

    void dfsHelper(int node, std::vector<bool>& visited) {
        visited[node] = true;
        std::cout << node << " ";
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

private:
    int numNodes;
    std::vector<std::list<int>> adjList;
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.dfs(0);  // Output: 0 1 3 2 4
    return 0;
}