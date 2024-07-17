#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int array[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int item) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow
");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->array[++q->rear] = item;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue underflow
");
        return -1;
    }
    int item = q->array[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty
");
        return -1;
    }
    return q->array[q->front];
}

// Test the queue
int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("%d
", peek(&q));  // Output: 1
    printf("%d
", dequeue(&q));  // Output: 1
    printf("%d
", dequeue(&q));  // Output: 2
    enqueue(&q, 4);
    printf("%d
", peek(&q));  // Output: 3
    printf("%d
", dequeue(&q));  // Output: 3
    printf("%d
", dequeue(&q));  // Output: 4
    
    return 0;
}