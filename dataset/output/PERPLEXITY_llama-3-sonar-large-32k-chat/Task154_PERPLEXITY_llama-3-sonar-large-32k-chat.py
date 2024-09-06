code here:
class Graph:
    def __init__(self, num_nodes):
        self.num_nodes = num_nodes
        self.adj_list = [[] for _ in range(num_nodes)]

    def add_edge(self, u, v):
        self.adj_list[u].append(v)

    def dfs(self, start_node):
        visited = [False] * self.num_nodes
        self._dfs_helper(start_node, visited)

    def _dfs_helper(self, node, visited):
        visited[node] = True
        print(node, end=" ")
        for neighbor in self.adj_list[node]:
            if not visited[neighbor]:
                self._dfs_helper(neighbor, visited)

# Example usage:
g = Graph(5)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 3)
g.add_edge(2, 4)
g.dfs(0)  # Output: 0 1 3 2 4