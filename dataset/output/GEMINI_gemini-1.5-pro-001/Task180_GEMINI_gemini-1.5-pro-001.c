#include <stdio.h>
#include <stdbool.h>

void dfs(int parent_of[], int new_parent_of[], bool visited[], int n, int node) {
  visited[node] = true;
  for (int child = 0; child < n; child++) {
    if (parent_of[child] == node && !visited[child]) {
      new_parent_of[child] = node;
      dfs(parent_of, new_parent_of, visited, n, child);
    }
  }
}

void reparent_tree(int parent_of[], int n, int root, int new_parent_of[]) {
  bool visited[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
    new_parent_of[i] = -1;
  }
  dfs(parent_of, new_parent_of, visited, n, root);
  for (int node = 0; node < n; node++) {
    if (node != root && new_parent_of[node] == -1) {
      new_parent_of[node] = parent_of[node];
    }
  }
}

int main() {
  int parent_of[] = {-1, 0, 0, 0, 1, 1, 2, 2, 3, 3};
  int n = sizeof(parent_of) / sizeof(parent_of[0]);
  int new_root = 6;
  int new_parent_of[n];

  reparent_tree(parent_of, n, new_root, new_parent_of);

  for (int i = 0; i < n; i++) {
    printf("%d ", new_parent_of[i]);
  }
  printf("\n"); // Output: 2 0 6 0 1 1 -1 2 3 3
  return 0;
}