#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
} Deque;

Deque *createDeque(int capacity) {
    Deque *deque = (Deque *)malloc(sizeof(Deque));
    deque->capacity = capacity;
    deque->front = deque->size = 0;
    deque->rear = capacity - 1;
    deque->array = (int *)malloc(deque->capacity * sizeof(int));
    return deque;
}

int isEmpty(Deque *deque) {
    return (deque->size == 0);
}

int isFull(Deque *deque) {
    return (deque->size == deque->capacity);
}

void insertRear(Deque *deque, int item) {
    if (isFull(deque)) {
        return;
    }
    deque->rear = (deque->rear + 1) % deque->capacity;
    deque->array[deque->rear] = item;
    deque->size = deque->size + 1;
}

void deleteFront(Deque *deque) {
    if (isEmpty(deque)) {
        return;
    }
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size = deque->size - 1;
}

int getFront(Deque *deque) {
    if (isEmpty(deque)) {
        return INT_MIN;
    }
    return deque->array[deque->front];
}

int getRear(Deque *deque) {
    if (isEmpty(deque)) {
        return INT_MIN;
    }
    return deque->array[deque->rear];
}

int shortestSubarray(int* nums, int numsSize, int k) {
    int n = numsSize;
    long long preSum[n + 1];
    preSum[0] = 0;
    for (int i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    int res = INT_MAX;
    Deque *queue = createDeque(n + 1);
    for (int i = 0; i < n + 1; i++) {
        while (!isEmpty(queue) && preSum[i] - preSum[getFront(queue)] >= k) {
            res = (res < i - getFront(queue)) ? res : (i - getFront(queue));
            deleteFront(queue);
        }
        while (!isEmpty(queue) && preSum[i] <= preSum[getRear(queue)]) {
            deleteRear(queue);
        }
        insertRear(queue, i);
    }
    return (res == INT_MAX) ? -1 : res;
}