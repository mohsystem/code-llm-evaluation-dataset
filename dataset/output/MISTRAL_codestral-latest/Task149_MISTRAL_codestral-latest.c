#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = item;
    temp->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL)
        return -1;

    Node* temp = queue->front;
    int item = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return item;
}

int peek(Queue* queue) {
    if (queue->front == NULL)
        return -1;

    return queue->front->data;
}