import queue

class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v):
        if u in self.graph:
            self.graph[u].append(v)
        else:
            self.graph[u] = [v]

    def bfs(self, start):
        visited = set()
        q = queue.Queue()
        q.put(start)
        visited.add(start)

        while not q.empty():
            node = q.get()
            print(node, end=' ')

            for neighbour in self.graph.get(node, []):
                if neighbour not in visited:
                    q.put(neighbour)
                    visited.add(neighbour)

g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

g.bfs(2)