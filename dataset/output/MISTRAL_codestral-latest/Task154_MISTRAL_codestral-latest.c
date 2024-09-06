// C

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 6

void dfs(int graph[MAX_NODES][MAX_NODES], int node, bool visited[MAX_NODES]) {
    if (!visited[node]) {
        visited[node] = true;
        printf("%c ", 'A' + node);
        for (int neighbour = 0; neighbour < MAX_NODES; neighbour++) {
            if (graph[node][neighbour] == 1) {
                dfs(graph, neighbour, visited);
            }
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    bool visited[MAX_NODES] = {false};
    dfs(graph, 0, visited);

    return 0;
}