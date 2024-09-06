#include <iostream>
#include <vector>

using namespace std;

vector<int> reparentTree(const vector<int>& parentOf, int root) {
  int n = parentOf.size();
  vector<int> newParentOf(n, -1);
  vector<bool> visited(n, false);

  function<void(int)> dfs = [&](int node) {
    visited[node] = true;
    for (int child = 0; child < n; ++child) {
      if (parentOf[child] == node && !visited[child]) {
        newParentOf[child] = node;
        dfs(child);
      }
    }
    if (node != root) {
      newParentOf[node] = parentOf[node];
    }
  };

  dfs(root);
  return newParentOf;
}

int main() {
  vector<int> parentOf = {-1, 0, 0, 0, 1, 1, 2, 2, 3, 3};
  int newRoot = 6;
  vector<int> newParentOf = reparentTree(parentOf, newRoot);
  for (int p : newParentOf) {
    cout << p << " ";
  }
  cout << endl;  // Output: 2 0 6 0 1 1 -1 2 3 3
  return 0;
}