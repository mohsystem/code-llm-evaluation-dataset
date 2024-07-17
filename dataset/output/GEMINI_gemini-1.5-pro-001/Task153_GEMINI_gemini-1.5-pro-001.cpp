#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void bfs(const unordered_map<char, vector<char>>& graph, char start_node) {
  unordered_set<char> visited;
  queue<char> q;

  visited.insert(start_node);
  q.push(start_node);

  while (!q.empty()) {
    char node = q.front();
    q.pop();
    cout << node << " ";

    for (char neighbor : graph.at(node)) {
      if (visited.find(neighbor) == visited.end()) {
        visited.insert(neighbor);
        q.push(neighbor);
      }
    }
  }
}

int main() {
  unordered_map<char, vector<char>> graph = {
    {'A', {'B', 'C'}},
    {'B', {'A', 'D', 'E'}},
    {'C', {'A', 'F'}},
    {'D', {'B'}},
    {'E', {'B', 'F'}},
    {'F', {'C', 'E'}}
  };
  char start_node = 'A';
  bfs(graph, start_node);
  return 0;
}