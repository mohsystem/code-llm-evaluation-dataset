code here:
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
public:
    int numNodes;
    vector<list<int>> adjList;

    Graph(int numNodes) : numNodes(numNodes), adjList(numNodes) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void dfs(int startNode) {
        vector<bool> visited(numNodes, false);
        dfsHelper(startNode, visited);
    }

    void dfsHelper(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "Depth-first search starting from node 0:" << endl;
    g.dfs(0);
    return 0;
}