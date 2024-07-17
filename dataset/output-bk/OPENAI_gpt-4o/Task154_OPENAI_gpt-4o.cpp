// C++ part
#include <iostream>
#include <vector>
#include <map>
#include <set>

void depthFirstSearch(std::map<char, std::vector<char>>& graph, char node, std::set<char>& visited) {
    if (visited.find(node) == visited.end()) {
        std::cout << node << std::endl;
        visited.insert(node);
        for (char neighbour : graph[node]) {
            depthFirstSearch(graph, neighbour, visited);
        }
    }
}

int main() {
    std::map<char, std::vector<char>> graph;
    graph['A'] = {'B', 'C'};
    graph['B'] = {'D', 'E'};
    graph['C'] = {'F'};
    graph['D'] = {};
    graph['E'] = {};
    graph['F'] = {};

    std::set<char> visited;
    depthFirstSearch(graph, 'A', visited);
    return 0;
}