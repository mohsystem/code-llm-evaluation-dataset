#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    string name;
    int distance;
};

bool operator<(const Node& a, const Node& b) {
    return a.distance > b.distance;
}

unordered_map<string, unordered_map<string, int>> graph = {
    {"A", {{"B", 1}, {"C", 4}}},
    {"B", {{"A", 1}, {"C", 2}, {"D", 5}}},
    {"C", {{"A", 4}, {"B", 2}, {"D", 1}}},
    {"D", {{"B", 5}, {"C", 1}}}
};

unordered_map<string, int> dijkstra(unordered_map<string, unordered_map<string, int>> graph, string start) {
    unordered_map<string, int> distances;
    for (auto& node : graph) {
        distances[node.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;

    priority_queue<Node> priorityQueue;
    priorityQueue.push({start, 0});

    while (!priorityQueue.empty()) {
        Node currentNode = priorityQueue.top();
        priorityQueue.pop();

        if (currentNode.distance > distances[currentNode.name]) {
            continue;
        }

        for (auto& neighbor : graph[currentNode.name]) {
            int distance = currentNode.distance + neighbor.second;

            if (distance < distances[neighbor.first]) {
                distances[neighbor.first] = distance;
                priorityQueue.push({neighbor.first, distance});
            }
        }
    }

    return distances;
}

int main() {
    string startNode = "A";
    unordered_map<string, int> distances = dijkstra(graph, startNode);
    for (auto& node : distances) {
        cout << node.first << ": " << node.second << endl;
    }
    return 0;
}