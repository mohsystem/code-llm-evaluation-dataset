// C part
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    char node;
    char neighbours[MAX_NODES];
    int neighbour_count;
} GraphNode;

GraphNode graph[MAX_NODES];
int graph_size = 0;
char visited[MAX_NODES];
int visited_count = 0;

void add_edge(char u, char v) {
    int i;
    for (i = 0; i < graph_size; i++) {
        if (graph[i].node == u) {
            graph[i].neighbours[graph[i].neighbour_count++] = v;
            return;
        }
    }
    graph[graph_size].node = u;
    graph[graph_size].neighbour_count = 1;
    graph[graph_size].neighbours[0] = v;
    graph_size++;
}

void depth_first_search(char node) {
    int i, j;
    
    for (i = 0; i < visited_count; i++) {
        if (visited[i] == node) return;
    }
    
    printf("%c
", node);
    visited[visited_count++] = node;
    
    for (i = 0; i < graph_size; i++) {
        if (graph[i].node == node) {
            for (j = 0; j < graph[i].neighbour_count; j++) {
                depth_first_search(graph[i].neighbours[j]);
            }
            return;
        }
    }
}

int main() {
    add_edge('A', 'B');
    add_edge('A', 'C');
    add_edge('B', 'D');
    add_edge('B', 'E');
    add_edge('C', 'F');
    
    depth_first_search('A');
    
    return 0;
}