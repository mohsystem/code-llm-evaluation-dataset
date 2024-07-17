def dfs(graph, node, visited):
    if node not in visited:
        visited.add(node)
        for n in graph[node]:
            dfs(graph, n, visited)

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

visited = set()
dfs(graph, 'A', visited)
print(visited)