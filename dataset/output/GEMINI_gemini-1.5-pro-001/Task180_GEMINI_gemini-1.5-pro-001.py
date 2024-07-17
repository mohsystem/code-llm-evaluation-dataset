from collections import defaultdict

def reparent_tree(parent, new_root):
  n = len(parent)
  child = defaultdict(list)
  for i in range(n):
    if parent[i] != -1:
      child[parent[i]].append(i)

  new_parent = [-1] * n
  def dfs(node, prev):
    new_parent[node] = prev
    for c in child[node]:
      if c != prev:
        dfs(c, node)

  dfs(new_root, -1)
  return new_parent