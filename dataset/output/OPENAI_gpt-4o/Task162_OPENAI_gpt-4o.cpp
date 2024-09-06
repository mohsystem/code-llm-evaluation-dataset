#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

typedef pair<int, string> P;
unordered_map<string, unordered_map<string, int>> graph = {
    {"A", {{"B", 1}, {"C", 4}}},
    {"B", {{"A", 1}, {"C", 2}, {"D", 5}}},
    {"C", {{"A", 4}, {"B", 2}, {"D", 1}}},
    {"D", {{"B", 5}, {"C", 1}}}
};

unordered_map<string, int> dijkstra(const string& start) {
    priority_queue<P, vector<P>, greater<P>> pq;
    unordered_map<string, int> distances;
    for (const auto& node : graph) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        string current_node = pq.top().second;
        pq.pop();

        for (const auto& neighbor : graph[current_node]) {
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
    string start_node = "A";
    unordered_map<string, int> distances = dijkstra(start_node);
    for (const auto& distance : distances) {
        cout << distance.first << ": " << distance.second << endl;
    }
    return 0;
}