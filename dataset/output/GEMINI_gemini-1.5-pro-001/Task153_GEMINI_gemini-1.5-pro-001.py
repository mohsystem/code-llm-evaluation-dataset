from collections import defaultdict

def bfs(graph, start_node):
  visited = set()
  queue = [start_node]
  visited.add(start_node)

  while queue:
    node = queue.pop(0)
    print(node, end=" ")

    for neighbor in graph[node]:
      if neighbor not in visited:
        visited.add(neighbor)
        queue.append(neighbor)

if __name__ == '__main__':
  graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
  }
  start_node = 'A'
  bfs(graph, start_node)