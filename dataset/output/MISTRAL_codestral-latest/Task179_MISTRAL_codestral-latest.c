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
    if (deque->rear == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    }
    deque->data[deque->front] = value;
    deque->size++;
}

int popFront(Deque* deque) {
    if (deque->size == 0) {
        return -1;
    }
    int value = deque->data[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->front = (deque->front + 1) % deque->capacity;
    }
    deque->size--;
    return value;
}

int popBack(Deque* deque) {
    if (deque->size == 0) {
        return -1;
    }
    int value = deque->data[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else {
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    }
    deque->size--;
    return value;
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
    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;
    Deque* window = createDeque(numsSize);

    for (int i = 0; i < numsSize; i++) {
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

    destroyDeque(window);
    return result;
}