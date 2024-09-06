def depth_first_search(graph, start_node):
    visited = set()
    stack = [start_node]

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            print(node, end=" ")  # Process the node here

            # Push unvisited neighbors onto the stack
            neighbors = graph[node]
            for neighbor in neighbors:
                if neighbor not in visited:
                    stack.append(neighbor)

# Example graph represented as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

start_node = 'A'
depth_first_search(graph, start_node)