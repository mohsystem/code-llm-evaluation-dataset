#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

// Structure to represent a node in the adjacency list
struct Node {
    int dest;
    int weight;
    struct Node* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};

// Structure to represent a graph
struct Graph {
    int num_nodes;
    struct AdjList* array;
};

// Function to create a new node in the adjacency list
struct Node* new_node(int dest, int weight) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Function to create a graph with a given number of nodes
struct Graph* create_graph(int num_nodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_nodes = num_nodes;
    graph->array = (struct AdjList*)malloc(num_nodes * sizeof(struct AdjList));
    for (int i = 0; i < num_nodes; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void add_edge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* node = new_node(dest, weight);
    node->next = graph->array[src].head;
    graph->array[src].head = node;
}

// Function to find the node with the minimum distance value,
// from the set of nodes not yet included in the shortest path tree
int min_distance(int dist[], int visited[], int num_nodes) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < num_nodes; ++i) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    for (int i = 0; i < graph->num_nodes; ++i) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < graph->num_nodes - 1; ++count) {
        int u = min_distance(dist, visited, graph->num_nodes);
        visited[u] = 1;

        struct Node* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + pCrawl->weight < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
            }
            pCrawl = pCrawl->next;
        }
    }

    printf("Vertex   Distance from Source
");
    for (int i = 0; i < graph->num_nodes; ++i) {
        printf("%d \t\t %d
", i, dist[i]);
    }
}

int main() {
    int num_nodes = 5;
    struct Graph* graph = create_graph(num_nodes);
    add_edge(graph, 0, 1, 4);
    add_edge(graph, 0, 2, 2);
    add_edge(graph, 1, 2, 1);
    add_edge(graph, 1, 3, 5);
    add_edge(graph, 2, 3, 8);
    add_edge(graph, 2, 4, 10);
    add_edge(graph, 3, 4, 2);

    dijkstra(graph, 0);

    return 0;
}