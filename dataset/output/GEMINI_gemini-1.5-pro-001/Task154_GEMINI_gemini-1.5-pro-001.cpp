#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void depthFirstSearch(const unordered_map<char, vector<char>>& graph, char startNode) {
    unordered_set<char> visited;
    stack<char> stack;
    stack.push(startNode);

    while (!stack.empty()) {
        char node = stack.top();
        stack.pop();
        if (visited.find(node) == visited.end()) {
            visited.insert(node);
            cout << node << " "; // Process the node here

            // Push unvisited neighbors onto the stack
            for (int i = graph.at(node).size() - 1; i >= 0; --i) {
                char neighbor = graph.at(node)[i];
                if (visited.find(neighbor) == visited.end()) {
                    stack.push(neighbor);
                }
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };

    char startNode = 'A';
    depthFirstSearch(graph, startNode);

    return 0;
}