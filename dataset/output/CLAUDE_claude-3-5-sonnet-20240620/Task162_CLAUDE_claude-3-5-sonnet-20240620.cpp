
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <string>

using namespace std;

typedef pair<int, string> pis;

unordered_map<string, int> dijkstra(const unordered_map<string, unordered_map<string, int>>& graph, const string& start) {
    unordered_map<string, int> distances;
    for (const auto& node : graph) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;

    priority_queue<pis, vector<pis>, greater<pis>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        string current_node = pq.top().second;
        pq.pop();

        if (current_distance > distances[current_node]) {
            continue;
        }

        for (const auto& neighbor : graph.at(current_node)) {
            int distance = current_distance + neighbor.second;
            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                pq.push({distance, neighbor.first});
            }
        }
    }

    return distances;
}

int main() {
    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 4}, {"C", 2}}},
        {"B", {{"D", 3}, {"E", 1}}},
        {"C", {{"B", 1}, {"D", 5}}},
        {"D", {{"E", 2}}},
        {"E", {}}
    };

    string start_node = "A";
    unordered_map<string, int> shortest_paths = dijkstra(graph, start_node);

    for (const auto& path : shortest_paths) {
        cout << path.first << ": " << path.second << endl;
    }

    return 0;
}
