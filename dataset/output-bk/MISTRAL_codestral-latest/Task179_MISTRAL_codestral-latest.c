#include <stdlib.h>

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} Deque;

Deque* createDeque(int capacity) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->data = (int*)malloc(capacity * sizeof(int));
    deque->front = -1;
    deque->rear = -1;
    deque->size = 0;
    deque->capacity = capacity;
    return deque;
}

void destroyDeque(Deque* deque) {
    free(deque->data);
    free(deque);
}

void pushBack(Deque* deque, int value) {
    if (deque->size == deque->capacity) {
        return;
    }
    if (deque->rear == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % deque->capacity;
    }
    deque->data[deque->rear] = value;
    deque->size++;
}

void pushFront(Deque* deque, int value) {
    if (deque->size == deque->capacity) {
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    }
    deque->data[deque->front] = value;
    deque->size++;
}

void popFront(Deque* deque) {
    if (deque->size == 0) {
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % deque->capacity;
    }
    deque->size--;
}

void popBack(Deque* deque) {
    if (deque->size == 0) {
        return;
    }
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    }
    deque->size--;
}

int front(Deque* deque) {
    if (deque->size == 0) {
        return -1;
    }
    return deque->data[deque->front];
}

int back(Deque* deque) {
    if (deque->size == 0) {
        return -1;
    }
    return deque->data[deque->rear];
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int n = numsSize;
    int* result = (int*)malloc((n - k + 1) * sizeof(int));
    Deque* window = createDeque(n);

    for (int i = 0; i < n; i++) {
        while (window->size > 0 && window->front <= i - k) {
            popFront(window);
        }
        while (window->size > 0 && nums[back(window)] < nums[i]) {
            popBack(window);
        }
        pushBack(window, i);
        if (i >= k - 1) {
            result[i - k + 1] = nums[front(window)];
        }
    }

    *returnSize = n - k + 1;
    destroyDeque(window);
    return result;
}