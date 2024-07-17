#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class Graph {
public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
    
    void bfs(int start) {
        std::unordered_set<int> visited;
        std::queue<int> q;
        q.push(start);
        visited.insert(start);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";
            
            for (int neighbor : adjList[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
    
private:
    std::unordered_map<int, std::vector<int>> adjList;
};

int main() {
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    
    graph.bfs(2);
    
    return 0;
}