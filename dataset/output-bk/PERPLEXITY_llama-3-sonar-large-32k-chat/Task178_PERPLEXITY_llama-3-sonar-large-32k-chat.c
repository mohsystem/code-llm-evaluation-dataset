#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->arr = (int*)malloc(sizeof(int) * capacity);
    deque->size = 0;
    deque->capacity = capacity;
    return deque;
}

void pushFront(Deque* deque, int val) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (int*)realloc(deque->arr, sizeof(int) * deque->capacity);
    }
    for (int i = deque->size; i > 0; i--) {
        deque->arr[i] = deque->arr[i - 1];
    }
    deque->arr[0] = val;
    deque->size++;
}

void pushBack(Deque* deque, int val) {
    if (deque->size == deque->capacity) {
        deque->capacity *= 2;
        deque->arr = (int*)realloc(deque->arr, sizeof(int) * deque->capacity);
    }
    deque->arr[deque->size] = val;
    deque->size++;
}

int popFront(Deque* deque) {
    int val = deque->arr[0];
    for (int i = 0; i < deque->size - 1; i++) {
        deque->arr[i] = deque->arr[i + 1];
    }
    deque->size--;
    return val;
}

int popBack(Deque* deque) {
    int val = deque->arr[deque->size - 1];
    deque->size--;
    return val;
}

int shortestSubarray(int* nums, int numsSize, int k) {
    int n = numsSize;
    int* prefix = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    int res = n + 1;
    Deque* queue = createDeque(10);
    for (int i = 0; i <= n; i++) {
        while (queue->size > 0 && prefix[i] - prefix[queue->arr[0]] >= k) {
            res = res < i - queue->arr[0] ? res : i - queue->arr[0];
            popFront(queue);
        }
        while (queue->size > 0 && prefix[queue->arr[queue->size - 1]] >= prefix[i]) {
            popBack(queue);
        }
        pushBack(queue, i);
    }
    return res <= n ? res : -1;
}