
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

bool isFull(Queue* q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->items[q->rear] = item;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\\n");
        return -1;  // Assuming -1 as an invalid value
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return item;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\\n");
        return -1;  // Assuming -1 as an invalid value
    }
    return q->items[q->front];
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("%d\\n", peek(&q));  // Output: 1
    printf("%d\\n", dequeue(&q));  // Output: 1
    printf("%d\\n", dequeue(&q));  // Output: 2
    printf("%d\\n", isEmpty(&q));  // Output: 0 (false)
    printf("%d\\n", dequeue(&q));  // Output: 3
    printf("%d\\n", isEmpty(&q));  // Output: 1 (true)

    return 0;
}
