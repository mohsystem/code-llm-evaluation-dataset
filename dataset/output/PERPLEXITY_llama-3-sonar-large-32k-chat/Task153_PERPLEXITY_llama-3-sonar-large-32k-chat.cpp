#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int numNodes;
    vector<vector<int>> adjList;
    vector<bool> visited;

    Graph(int numNodes) {
        this->numNodes = numNodes;
        this->adjList.resize(numNodes);
        this->visited.resize(numNodes, false);
    }

    void addEdge(int u, int v) {
        this->adjList[u].push_back(v);
    }

    void bfs(int startNode) {
        queue<int> q;

        q.push(startNode);
        this->visited[startNode] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : this->adjList[node]) {
                if (!this->visited[neighbor]) {
                    q.push(neighbor);
                    this->visited[neighbor] = true;
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