#include <iostream>
#include <vector>

using namespace std;

vector<int> reparent_tree(const vector<int>& parent, int new_root) {
  int n = parent.size();
  vector<vector<int>> children(n);
  for (int i = 0; i < n; ++i) {
    if (parent[i] != -1) {
      children[parent[i]].push_back(i);
    }
  }
  vector<int> new_parent(n, -1);
  function<void(int, int)> dfs = [&](int node, int prev) {
    new_parent[node] = prev;
    for (int child : children[node]) {
      if (child != prev) {
        dfs(child, node);
      }
    }
  };
  dfs(new_root, -1);
  return new_parent;
}

int main() {
  vector<int> parent = {0, 0, 0, 1, 1, 2, 2};
  int new_root = 2;
  vector<int> new_parent = reparent_tree(parent, new_root);
  for (int p : new_parent) {
    cout << p << " ";
  }
  cout << endl;
  return 0;
}