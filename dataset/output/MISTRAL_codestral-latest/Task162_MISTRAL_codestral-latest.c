#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 100

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < MAX_NODES; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[MAX_NODES][MAX_NODES], int src, int numNodes) {
    int dist[MAX_NODES];
    bool sptSet[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < numNodes; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from node %d:
", src);
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %d
", i, dist[i]);
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 4, 0},
        {1, 0, 2, 5},
        {4, 2, 0, 1},
        {0, 5, 1, 0}
    };

    int numNodes = 4;
    int startNode = 0;

    dijkstra(graph, startNode, numNodes);

    return 0;
}