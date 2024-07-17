#include <iostream>
#include <map>
#include <list>
#include <set>
#include <algorithm>

void dfs(std::map<char, std::list<char>> graph, char node, std::set<char>& visited) {
    if (visited.find(node) == visited.end()) {
        visited.insert(node);
        for (char n : graph[node]) {
            dfs(graph, n, visited);
        }
    }
}

int main() {
    std::map<char, std::list<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'A', 'D', 'E'}},
        {'C', {'A', 'F'}},
        {'D', {'B'}},
        {'E', {'B', 'F'}},
        {'F', {'C', 'E'}}
    };

    std::set<char> visited;
    dfs(graph, 'A', visited);
    for (char node : visited) {
        std::cout << node << " ";
    }
    std::cout << std::endl;
    return 0;
}