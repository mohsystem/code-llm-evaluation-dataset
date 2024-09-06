
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int distance;
} Node;

typedef struct {
    char from[MAX_NAME_LENGTH];
    char to[MAX_NAME_LENGTH];
    int weight;
} Edge;

int find_node_index(char name[], Node nodes[], int node_count) {
    for (int i = 0; i < node_count; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void dijkstra(Node nodes[], int node_count, Edge edges[], int edge_count, char start[]) {
    int distances[MAX_NODES];
    int visited[MAX_NODES] = {0};

    for (int i = 0; i < node_count; i++) {
        distances[i] = INT_MAX;
    }

    int start_index = find_node_index(start, nodes, node_count);
    distances[start_index] = 0;

    for (int i = 0; i < node_count - 1; i++) {
        int min_dist = INT_MAX;
        int min_index = -1;

        for (int j = 0; j < node_count; j++) {
            if (!visited[j] && distances[j] < min_dist) {
                min_dist = distances[j];
                min_index = j;
            }
        }

        if (min_index == -1) break;

        visited[min_index] = 1;

        for (int j = 0; j < edge_count; j++) {
            if (strcmp(edges[j].from, nodes[min_index].name) == 0) {
                int to_index = find_node_index(edges[j].to, nodes, node_count);
                if (!visited[to_index] && distances[min_index] != INT_MAX &&
                    distances[min_index] + edges[j].weight < distances[to_index]) {
                    distances[to_index] = distances[min_index] + edges[j].weight;
                }
            }
        }
    }

    printf("Shortest distances from %s:\\n", start);
    for (int i = 0; i < node_count; i++) {
        printf("%s: %d\\n", nodes[i].name, distances[i]);
    }
}

int main() {
    Node nodes[] = {
        {"A", 0}, {"B", 0}, {"C", 0}, {"D", 0}, {"E", 0}
    };
    int node_count = sizeof(nodes) / sizeof(nodes[0]);

    Edge edges[] = {
        {"A", "B", 4}, {"A", "C", 2},
        {"B", "D", 3}, {"B", "E", 1},
        {"C", "B", 1}, {"C", "D", 5},
        {"D", "E", 2}
    };
    int edge_count = sizeof(edges) / sizeof(edges[0]);

    char start[] = "A";
    dijkstra(nodes, node_count, edges, edge_count, start);

    return 0;
}
