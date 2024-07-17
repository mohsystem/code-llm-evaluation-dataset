#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int items[MAX];
    int front;
    int rear;
} queue;

struct Graph {
    int adjMatrix[MAX][MAX];
    int numVertices;
};

void initQueue() {
    queue.front = -1;
    queue.rear = -1;
}

int isEmpty() {
    if (queue.rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(int value) {
    if (queue.rear == MAX - 1)
        printf("
Queue is Full
");
    else {
        if (queue.front == -1)
            queue.front = 0;
        queue.rear++;
        queue.items[queue.rear] = value;
    }
}

int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = queue.items[queue.front];
        queue.front++;
        if (queue.front > queue.rear) {
            queue.front = queue.rear = -1;
        }
    }
    return item;
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
}

void bfs(struct Graph* graph, int startVertex) {
    initQueue();
    
    int visited[MAX];
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;

    visited[startVertex] = 1;
    enqueue(startVertex);
    
    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = 4;
    
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            graph->adjMatrix[i][j] = 0;

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    bfs(graph, 2);
    
    free(graph);
    
    return 0;
}