#include <iostream>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a node in the priority queue
struct Node {
    string vertex;
    int distance;

    Node(string v, int d) : vertex(v), distance(d) {}
};

// Custom comparator for priority queue
struct CompareDistance {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.distance > n2.distance;
    }
};

unordered_map<string, int> dijkstra(const unordered_map<string, unordered_map<string, int>>& graph, const string& start) {
    unordered_map<string, int> distances;
    for (const auto& pair : graph) {
        distances[pair.first] = numeric_limits<int>::max();
    }
    distances[start] = 0;

    priority_queue<Node, vector<Node>, CompareDistance> queue;
    queue.push(Node(start, 0));
    unordered_set<string> visited;

    while (!queue.empty()) {
        Node current = queue.top();
        queue.pop();

        if (visited.find(current.vertex) != visited.end()) {
            continue;
        }
        visited.insert(current.vertex);

        for (const auto& neighborPair : graph[current.vertex]) {
            string neighbor = neighborPair.first;
            int weight = neighborPair.second;
            int distance = distances[current.vertex] + weight;

            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                queue.push(Node(neighbor, distance));
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
    unordered_map<string, int> distances = dijkstra(graph, startNode);

    cout << "Shortest distances from node " << startNode << ": " << endl;
    for (const auto& pair : distances) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}