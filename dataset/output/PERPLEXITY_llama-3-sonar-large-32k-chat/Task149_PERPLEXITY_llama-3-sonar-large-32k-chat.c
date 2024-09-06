#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[20];
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue* q, const char* item) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->data, item);
    node->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

char* dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    Node* node = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    char* item = (char*)malloc(sizeof(char) * 20);
    strcpy(item, node->data);
    free(node);
    return item;
}

char* peek(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }
    char* item = (char*)malloc(sizeof(char) * 20);
    strcpy(item, q->front->data);
    return item;
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, "Apple");
    enqueue(&q, "Banana");
    enqueue(&q, "Cherry");
    printf("%s\n", dequeue(&q));  // Apple
    printf("%s\n", peek(&q));  // Banana
    return 0;
}