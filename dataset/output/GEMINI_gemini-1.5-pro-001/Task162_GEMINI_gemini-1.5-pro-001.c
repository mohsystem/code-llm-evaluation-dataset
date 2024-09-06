#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
struct Edge {
    int dest;
    int weight;
};

// Structure to represent a node in the adjacency list
struct AdjListNode {
    int vertex;
    struct Edge edge;
    struct AdjListNode* next;
};

// Structure to represent the adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->vertex = dest;
    newNode->edge.dest = dest;
    newNode->edge.weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[], int numVertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < numVertices; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int numVertices) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX_VERTICES];  // The output array.  dist[i] will hold the shortest distance from src to i
    int sptSet[MAX_VERTICES]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < graph->numVertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < graph->numVertices - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet, graph->numVertices);
        
        // Mark the picked vertex as processed
        sptSet[u] = 1;
        
        // Update dist value of the adjacent vertices of the picked vertex.
        struct AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->vertex;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + pCrawl->edge.weight < dist[v]) {
                dist[v] = dist[u] + pCrawl->edge.weight;
            }
            pCrawl = pCrawl->next;
        }
    }
    
    // Print the constructed distance array
    printSolution(dist, graph->numVertices);
}

// Driver program to test above functions
int main() {
    int numVertices = 4;
    struct Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1, 1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 1);

    dijkstra(graph, 0);

    return 0;
}