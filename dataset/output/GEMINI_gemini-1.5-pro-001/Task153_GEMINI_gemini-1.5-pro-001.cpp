#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

void breadthFirstSearch(const vector<list<int>>& graph, int startNode) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    vector<list<int>> graph;
    // Add edges to the graph (example)
    graph.push_back({1, 2});
    graph.push_back({3, 4});
    graph.push_back({5});
    graph.push_back({});
    graph.push_back({5});
    graph.push_back({});

    int startNode = 0;
    breadthFirstSearch(graph, startNode);

    return 0;
}