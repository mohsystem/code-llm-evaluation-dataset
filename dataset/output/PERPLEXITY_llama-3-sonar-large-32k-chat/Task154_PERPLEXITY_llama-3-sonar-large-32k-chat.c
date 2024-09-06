code here:
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int numNodes;
    int adjList[MAX_NODES][MAX_NODES];
} Graph;

void initGraph(Graph* g, int numNodes) {
    g->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            g->adjList[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int u, int v) {
    g->adjList[u][v] = 1;
}

void dfs(Graph* g, int startNode, bool visited[]) {
    visited[startNode] = true;
    printf("%d ", startNode);
    for (int neighbor = 0; neighbor < g->numNodes; neighbor++) {
        if (g->adjList[startNode][neighbor] && !visited[neighbor]) {
            dfs(g, neighbor, visited);
        }
    }
}

int main() {
    Graph g;
    initGraph(&g, 5);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    bool visited[5] = {false};
    dfs(&g, 0, visited);  // Output: 0 1 3 2 4
    return 0;
}