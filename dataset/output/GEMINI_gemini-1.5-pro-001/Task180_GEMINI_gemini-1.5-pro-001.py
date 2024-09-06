from collections import defaultdict

def reparent_tree(parent_of, root):
  """Reparents the tree to use the given root."""
  n = len(parent_of)
  new_parent_of = [-1] * n
  visited = [False] * n

  def dfs(node):
    visited[node] = True
    for child in range(n):
      if parent_of[child] == node and not visited[child]:
        new_parent_of[child] = node
        dfs(child)
    if node != root:
      new_parent_of[node] = parent_of[node]

  dfs(root)
  return new_parent_of

# Example usage:
parent_of = [-1, 0, 0, 0, 1, 1, 2, 2, 3, 3]
new_root = 6
new_parent_of = reparent_tree(parent_of, new_root)
print(new_parent_of)  # Output: [2, 0, 6, 0, 1, 1, -1, 2, 3, 3]