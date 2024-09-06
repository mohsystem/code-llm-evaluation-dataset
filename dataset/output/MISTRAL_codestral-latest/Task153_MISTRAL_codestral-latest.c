#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void bfs(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    struct Node* queue = createNode(startVertex);
    visited[startVertex] = 1;

    while (queue != NULL) {
        printf("%d ", queue->data);
        struct Node* temp = queue;
        queue = queue->next;
        free(temp);

        struct Node* adjList = graph->adjLists[queue->data];
        while (adjList != NULL) {
            int adjVertex = adjList->data;
            if (visited[adjVertex] == 0) {
                struct Node* newNode = createNode(adjVertex);
                if (queue == NULL)
                    queue = newNode;
                else {
                    struct Node* last = queue;
                    while (last->next != NULL)
                        last = last->next;
                    last->next = newNode;
                }
                visited[adjVertex] = 1;
            }
            adjList = adjList->next;
        }
    }

    free(visited);
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 4, 5);

    bfs(graph, 0);

    return 0;
}