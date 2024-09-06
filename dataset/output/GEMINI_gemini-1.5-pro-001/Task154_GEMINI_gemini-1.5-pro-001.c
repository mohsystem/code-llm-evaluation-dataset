#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Graph {
    int num_nodes;
    int adj_list[MAX_NODES][MAX_NODES];
};

bool visited[MAX_NODES];

void depthFirstSearch(struct Graph *graph, int start_node) {
    visited[start_node] = true;
    printf("%d ", start_node);

    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->adj_list[start_node][i] && !visited[i]) {
            depthFirstSearch(graph, i);
        }
    }
}

int main() {
    struct Graph graph = {
        .num_nodes = 6,
        .adj_list = {
            {0, 1, 1, 0, 0, 0},
            {1, 0, 0, 1, 1, 0},
            {1, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 1},
            {0, 0, 1, 0, 1, 0}
        }
    };

    int start_node = 0;
    depthFirstSearch(&graph, start_node);

    return 0;
}