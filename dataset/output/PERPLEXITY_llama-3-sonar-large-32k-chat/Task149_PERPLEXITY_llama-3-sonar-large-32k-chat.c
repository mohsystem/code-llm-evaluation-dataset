#include <stdio.h>
#include <string.h>

#define CAPACITY 5

typedef struct {
    char queue[CAPACITY][20];
    int front, rear, size;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = q->size = 0;
}

void enqueue(Queue* q, char* item) {
    if (q->size == CAPACITY) {
        printf("Queue is full
");
        return;
    }
    strcpy(q->queue[q->rear], item);
    q->rear = (q->rear + 1) % CAPACITY;
    q->size++;
}

char* dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty
");
        return NULL;
    }
    char* item = q->queue[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return item;
}

char* peek(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty
");
        return NULL;
    }
    return q->queue[q->front];
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, "Apple");
    enqueue(&q, "Banana");
    enqueue(&q, "Cherry");
    printf("%s
", dequeue(&q));  // Apple
    printf("%s
", peek(&q));  // Banana
    return 0;
}