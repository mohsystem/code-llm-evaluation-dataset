from collections import deque

class Graph:
    def __init__(self, num_nodes):
        self.num_nodes = num_nodes
        self.adj_list = [[] for _ in range(num_nodes)]

    def add_edge(self, u, v):
        self.adj_list[u].append(v)

    def bfs(self, start_node):
        visited = [False] * self.num_nodes
        queue = deque()

        queue.append(start_node)
        visited[start_node] = True

        while queue:
            node = queue.popleft()
            print(node, end=" ")

            for neighbor in self.adj_list[node]:
                if not visited[neighbor]:
                    queue.append(neighbor)
                    visited[neighbor] = True

# Example usage:
g = Graph(5)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(2, 4)

print("BFS traversal starting from node 0:")
g.bfs(0)