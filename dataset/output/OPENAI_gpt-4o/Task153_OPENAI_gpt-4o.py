import queue

def bfs(graph, start):
    visited = set()
    q = queue.Queue()
    q.put(start)
    visited.add(start)
    
    while not q.empty():
        node = q.get()
        print(node, end=" ")
        
        for neighbor in graph[node]:
            if neighbor not in visited:
                q.put(neighbor)
                visited.add(neighbor)

# Example usage:
# graph = {0: [1, 2], 1: [2], 2: [0, 3], 3: [3]}
# bfs(graph, 2)