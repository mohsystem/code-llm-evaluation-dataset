// C++

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void dfs(std::unordered_map<char, std::vector<char>>& graph, char node, std::unordered_set<char>& visited) {
    if (visited.find(node) == visited.end()) {
        visited.insert(node);
        std::cout << node << " ";
        for (char neighbour : graph[node]) {
            dfs(graph, neighbour, visited);
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

    std::unordered_set<char> visited;
    dfs(graph, 'A', visited);

    return 0;
}