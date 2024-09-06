#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Deque;

Deque *createDeque(int capacity) {
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    dq->arr = (int *)malloc(sizeof(int) * capacity);
    dq->front = -1;
    dq->rear = -1;
    dq->size = capacity;
    return dq;
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

int isFull(Deque *dq) {
    return ((dq->rear + 1) % dq->size == dq->front);
}

void insertRear(Deque *dq, int item) {
    if (isFull(dq)) {
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % dq->size;
    }
    dq->arr[dq->rear] = item;
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % dq->size;
    }
}

int getFront(Deque *dq) {
    if (isEmpty(dq)) {
        return -1; 
    }
    return dq->arr[dq->front];
}

int getRear(Deque *dq) {
    if (isEmpty(dq)) {
        return -1; 
    }
    return dq->arr[dq->rear];
}

int shortestSubarray(int* nums, int numsSize, int k) {
    long long preSum[numsSize + 1];
    preSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    int res = INT_MAX;
    Deque *q = createDeque(numsSize + 1);
    for (int i = 0; i <= numsSize; i++) {
        while (!isEmpty(q) && preSum[i] - preSum[getFront(q)] >= k) {
            res = (res < i - getFront(q)) ? res : (i - getFront(q));
            deleteFront(q);
        }
        while (!isEmpty(q) && preSum[i] <= preSum[getRear(q)]) {
            deleteRear(q);
        }
        insertRear(q, i);
    }
    free(q->arr);
    free(q);
    return (res == INT_MAX) ? -1 : res;
}