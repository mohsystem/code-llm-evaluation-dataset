#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

using namespace std;

typedef pair<int, string> pii;

vector<pii> graph[100];
unordered_map<string, int> distances;

void dijkstra(string start) {
    distances[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        int current_distance = pq.top().first;
        string current_node = pq.top().second;
        pq.pop();
        for (auto neighbor : graph[current_node[0] - 'A']) {
            if (current_distance + neighbor.first < distances[neighbor.second]) {
                distances[neighbor.second] = current_distance + neighbor.first;
                pq.push({distances[neighbor.second], neighbor.second});
            }
        }
    }
}

int main() {
    graph['A' - 'A'].push_back({1, "B"});
    graph['A' - 'A'].push_back({4, "C"});
    graph['B' - 'A'].push_back({1, "A"});
    graph['B' - 'A'].push_back({2, "C"});
    graph['B' - 'A'].push_back({5, "D"});
    graph['C' - 'A'].push_back({4, "A"});
    graph['C' - 'A'].push_back({2, "B"});
    graph['C' - 'A'].push_back({1, "D"});
    graph['D' - 'A'].push_back({5, "B"});
    graph['D' - 'A'].push_back({1, "C"});

    for (char c = 'A'; c <= 'D'; c++) {
        distances[string(1, c)] = numeric_limits<int>::max();
    }

    string startNode = "A";
    dijkstra(startNode);

    for (auto distance : distances) {
        cout << distance.first << ": " << distance.second << endl;
    }

    return 0;
}