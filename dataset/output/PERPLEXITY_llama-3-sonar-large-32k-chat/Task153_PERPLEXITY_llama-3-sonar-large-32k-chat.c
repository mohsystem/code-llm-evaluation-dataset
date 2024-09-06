#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Graph {
    int numNodes;
    int adjList[MAX_NODES][MAX_NODES];
    bool visited[MAX_NODES];
} Graph;

void addEdge(Graph* g, int u, int v) {
    g->adjList[u][v] = 1;
}

void bfs(Graph* g, int startNode) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = startNode;
    g->visited[startNode] = true;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int neighbor = 0; neighbor < g->numNodes; neighbor++) {
            if (g->adjList[node][neighbor] && !g->visited[neighbor]) {
                queue[rear++] = neighbor;
                g->visited[neighbor] = true;
            }
        }
    }
}

int main() {
    Graph g;
    g.numNodes = 5;

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);

    printf("BFS traversal starting from node 0: ");
    bfs(&g, 0);
    return 0;
}