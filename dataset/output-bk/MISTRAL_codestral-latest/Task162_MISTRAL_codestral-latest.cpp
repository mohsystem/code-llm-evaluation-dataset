#include <iostream>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

unordered_map<string, int> dijkstra(unordered_map<string, unordered_map<string, int>> graph, string start) {
    unordered_map<string, int> distances;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> priorityQueue;

    for (const auto& node : graph) {
        if (node.first == start) {
            distances[node.first] = 0;
            priorityQueue.push({0, node.first});
        } else {
            distances[node.first] = numeric_limits<int>::max();
            priorityQueue.push({numeric_limits<int>::max(), node.first});
        }
    }

    while (!priorityQueue.empty()) {
        string currentNodeName = priorityQueue.top().second;
        int currentDistance = priorityQueue.top().first;
        priorityQueue.pop();

        if (currentDistance > distances[currentNodeName]) {
            continue;
        }

        for (const auto& neighbor : graph[currentNodeName]) {
            int distance = distances[currentNodeName] + neighbor.second;

            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                priorityQueue.push({distance, neighbor.first});
            }
        }
    }

    return distances;
}

int main() {
    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 1}, {"C", 4}}},
        {"B", {{"A", 1}, {"C", 2}, {"D", 5}}},
        {"C", {{"A", 4}, {"B", 2}, {"D", 1}}},
        {"D", {{"B", 5}, {"C", 1}}}
    };

    string startNode = "A";
    unordered_map<string, int> shortestPaths = dijkstra(graph, startNode);

    for (const auto& node : shortestPaths) {
        cout << node.first << ": " << node.second << endl;
    }

    return 0;
}