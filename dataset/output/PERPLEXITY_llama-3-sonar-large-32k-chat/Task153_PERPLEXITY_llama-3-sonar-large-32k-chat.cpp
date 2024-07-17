#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int numNodes;
    vector<vector<int>> adjList;

    Graph(int numNodes) : numNodes(numNodes), adjList(numNodes) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void bfs(int startNode) {
        vector<bool> visited(numNodes, false);
        queue<int> q;

        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "BFS traversal starting from node 0: ";
    g.bfs(0);
    return 0;
}