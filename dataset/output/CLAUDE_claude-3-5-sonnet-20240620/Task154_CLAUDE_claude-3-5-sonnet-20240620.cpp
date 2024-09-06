
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> graph;

    void dfsUtil(int v, unordered_set<int>& visited) {
        visited.insert(v);
        cout << v << " ";

        for (int neighbour : graph[v]) {
            if (visited.find(neighbour) == visited.end()) {
                dfsUtil(neighbour, visited);
            }
        }
    }

public:
    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    void dfs(int v) {
        unordered_set<int> visited;
        dfsUtil(v, visited);
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal (starting from vertex 2):" << endl;
    g.dfs(2);

    return 0;
}
