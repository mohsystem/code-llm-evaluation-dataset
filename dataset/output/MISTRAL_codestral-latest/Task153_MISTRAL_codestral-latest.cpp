#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

void bfs(const std::unordered_map<char, std::vector<char>>& graph, char start) {
    std::unordered_set<char> visited;
    std::queue<char> queue;
    queue.push(start);

    while (!queue.empty()) {
        char node = queue.front();
        queue.pop();
        if (visited.find(node) == visited.end()) {
            std::cout << node << std::endl;
            visited.insert(node);
            for (char neighbor : graph.at(node)) {
                if (visited.find(neighbor) == visited.end()) {
                    queue.push(neighbor);
                }
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

    bfs(graph, 'A');

    return 0;
}