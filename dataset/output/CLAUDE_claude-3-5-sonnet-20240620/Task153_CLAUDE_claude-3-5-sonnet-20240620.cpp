
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void bfs(const std::unordered_map<char, std::vector<char>>& graph, char start) {
    std::unordered_set<char> visited;
    std::queue<char> queue;

    queue.push(start);
    visited.insert(start);

    while (!queue.empty()) {
        char vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";

        for (char neighbor : graph.at(vertex)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    std::unordered_map<char, std::vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    std::cout << "BFS starting from vertex 'A':" << std::endl;
    bfs(graph, 'A');

    return 0;
}
