#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numNodes;
    struct Node** adjList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;
    graph->adjList = (struct Node**)malloc(numNodes * sizeof(struct Node*));
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void bfs(struct Graph* graph, int start) {
    bool visited[MAX_NODES] = {false};
    struct Node* queue[MAX_NODES];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = createNode(start);

    while (front != rear) {
        struct Node* node = queue[front++];
        printf("%d ", node->data);

        struct Node* temp = graph->adjList[node->data];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = true;
                queue[rear++] = createNode(temp->data);
            }
            temp = temp->next;
        }
    }
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