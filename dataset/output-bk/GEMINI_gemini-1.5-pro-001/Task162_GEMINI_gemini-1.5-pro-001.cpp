#include <iostream>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

unordered_map<string, int> dijkstra(const unordered_map<string, unordered_map<string, int>>& graph, const string& start) {
    unordered_map<string, int> distances;
    for (const auto& [node, _] : graph) {
        distances[node] = numeric_limits<int>::max();
    }
    distances[start] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> queue;
    queue.push({0, start});

    unordered_set<string> visited;

    while (!queue.empty()) {
        int currentDistance;
        string currentNode;
        tie(currentDistance, currentNode) = queue.top();
        queue.pop();

        if (visited.count(currentNode)) {
            continue;
        }

        visited.insert(currentNode);

        for (const auto& [neighbor, weight] : graph.at(currentNode)) {
            int distance = currentDistance + weight;
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                queue.push({distance, neighbor});
            }
        }
    }

    return distances;
}

int main() {
    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 4}, {"C", 2}}},
        {"B", {{"C", 1}, {"D", 5}}},
        {"C", {{"D", 8}, {"E", 10}}},
        {"D", {{"E", 2}}},
        {"E", {}}
    };

    string startNode = "A";
    unordered_map<string, int> shortestDistances = dijkstra(graph, startNode);

    for (const auto& [node, distance] : shortestDistances) {
        cout << "Shortest distance from " << startNode << " to " << node << ": " << distance << endl;
    }

    return 0;
}