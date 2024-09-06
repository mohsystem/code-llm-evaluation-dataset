#include <iostream>
#include <list>
#include <queue>
#include <map>
#include <set>

class Graph {
    std::map<int, std::list<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void bfs(int start) {
        std::set<int> visited;
        std::queue<int> queue;
        queue.push(start);
        visited.insert(start);

        while (!queue.empty()) {
            int node = queue.front();
            std::cout << node << " ";
            queue.pop();

            for (int neighbour : adj[node]) {
                if (visited.find(neighbour) == visited.end()) {
                    queue.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
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

    g.bfs(2);

    return 0;
}