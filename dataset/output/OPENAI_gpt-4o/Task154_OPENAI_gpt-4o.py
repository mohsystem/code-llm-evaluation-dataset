import sys
from ctypes import *

class Node(Structure):
    pass

Node._fields_ = [("vertex", c_int), ("next", POINTER(Node))]

def create_node(vertex):
    node = Node()
    node.vertex = vertex
    node.next = None
    return node

class Stack(Structure):
    _fields_ = [("top", POINTER(Node)), ("size", c_int)]

def create_stack():
    stack = Stack()
    stack.top = None
    stack.size = 0
    return stack

def push(stack, vertex):
    new_node = create_node(vertex)
    new_node.next = stack.top
    stack.top = new_node
    stack.size += 1

def pop(stack):
    if stack.size > 0:
        vertex = stack.top.contents.vertex
        stack.top = stack.top.contents.next
        stack.size -= 1
        return vertex
    return -1

def dfs(graph, start):
    visited = (c_bool * 1000)()
    stack = create_stack()
    push(stack, start)
    while stack.size > 0:
        vertex = pop(stack)
        if not visited[vertex]:
            print(vertex, end=' ')
            visited[vertex] = True
        node = graph[vertex]
        while node:
            if not visited[node.vertex]:
                push(stack, node.vertex)
            node = node.next

def add_edge(graph, src, dest):
    new_node = create_node(dest)
    new_node.next = graph[src]
    graph[src] = new_node

def main(argc, argv):
    V = 5
    graph = (POINTER(Node) * V)()
    for i in range(V):
        graph[i] = None
    add_edge(graph, 0, 1)
    add_edge(graph, 0, 2)
    add_edge(graph, 1, 2)
    add_edge(graph, 2, 0)
    add_edge(graph, 2, 3)
    add_edge(graph, 3, 3)
    print("Depth First Traversal starting from vertex 2:")
    dfs(graph, 2)

if __name__ == "__main__":
    main(len(sys.argv), sys.argv)