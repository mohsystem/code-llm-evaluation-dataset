
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Graph {
private:
    std::unordered_map<int, std::vector<int>> graph;

    void dfsUtil(int v, std::unordered_set<int>& visited) {
        visited.insert(v);
        std::cout << v << " ";

        for (int neighbor : graph[v]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsUtil(neighbor, visited);
            }
        }
    }

public:
    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    void dfs(int start) {
        std::unordered_set<int> visited;
        dfsUtil(start, visited);
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

    std::cout << "Depth First Traversal (starting from vertex 2):\
";
    g.dfs(2);

    return 0;
}
