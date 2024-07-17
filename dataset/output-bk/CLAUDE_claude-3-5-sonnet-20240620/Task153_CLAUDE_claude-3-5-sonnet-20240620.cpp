
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void bfs(const std::unordered_map<int, std::vector<int>>& graph, int start) {
    std::unordered_set<int> visited;
    std::queue<int> queue;

    queue.push(start);
    visited.insert(start);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";

        for (int neighbor : graph.at(vertex)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    std::unordered_map<int, std::vector<int>> graph = {
        {0, {1, 2}},
        {1, {2}},
        {2, {0, 3}},
        {3, {3}}
    };

    std::cout << "BFS starting from vertex 2:" << std::endl;
    bfs(graph, 2);

    return 0;
}
