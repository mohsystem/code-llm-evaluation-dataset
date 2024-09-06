
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
};

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = false;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int v, int w) {
    graph->adj[v][w] = true;
}

void DFSUtil(struct Graph* graph, int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(struct Graph* graph, int v) {
    bool visited[MAX_VERTICES];
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }

    DFSUtil(graph, v, visited);
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("Depth First Traversal (starting from vertex 2):\\n");
    DFS(graph, 2);

    free(graph);
    return 0;
}
