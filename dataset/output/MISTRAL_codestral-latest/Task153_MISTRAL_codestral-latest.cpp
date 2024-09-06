#include <iostream>
#include <list>
#include <set>
#include <queue>

void bfs(std::map<char, std::list<char>> graph, char start) {
    std::set<char> visited;
    std::queue<char> queue;

    visited.insert(start);
    queue.push(start);

    while (!queue.empty()) {
        char node = queue.front();
        std::cout << node << " ";
        queue.pop();

        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    std::map<char, std::list<char>> graph;
    graph['A'] = {'B', 'C'};
    graph['B'] = {'A', 'D', 'E'};
    graph['C'] = {'A', 'F'};
    graph['D'] = {'B'};
    graph['E'] = {'B', 'F'};
    graph['F'] = {'C', 'E'};

    bfs(graph, 'A');

    return 0;
}