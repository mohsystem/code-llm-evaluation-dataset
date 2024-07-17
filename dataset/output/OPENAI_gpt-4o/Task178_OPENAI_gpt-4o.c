#include <stdio.h>
#include <stdlib.h>

struct deque {
    int *data;
    int head;
    int tail;
    int size;
    int capacity;
};

void deque_init(struct deque *dq, int capacity) {
    dq->data = (int *)malloc(sizeof(int) * capacity);
    dq->head = 0;
    dq->tail = 0;
    dq->size = 0;
    dq->capacity = capacity;
}

void deque_push_back(struct deque *dq, int value) {
    dq->data[dq->tail++] = value;
    if (dq->tail == dq->capacity) dq->tail = 0;
    dq->size++;
}

int deque_pop_front(struct deque *dq) {
    int value = dq->data[dq->head++];
    if (dq->head == dq->capacity) dq->head = 0;
    dq->size--;
    return value;
}

int deque_get_back(struct deque *dq) {
    return dq->tail == 0 ? dq->data[dq->capacity - 1] : dq->data[dq->tail - 1];
}

int deque_get_front(struct deque *dq) {
    return dq->data[dq->head];
}

int deque_is_empty(struct deque *dq) {
    return dq->size == 0;
}

void deque_clear(struct deque *dq) {
    dq->head = dq->tail = dq->size = 0;
}

void deque_free(struct deque *dq) {
    free(dq->data);
}

int shortestSubarray(int* nums, int numsSize, int k) {
    int n = numsSize;
    int *P = (int *)malloc(sizeof(int) * (n + 1));
    P[0] = 0;
    for (int i = 0; i < n; i++) {
        P[i + 1] = P[i] + nums[i];
    }

    int ans = n + 1;
    struct deque monoq;
    deque_init(&monoq, n + 1);

    for (int y = 0; y <= n; y++) {
        while (!deque_is_empty(&monoq) && P[y] <= P[deque_get_back(&monoq)]) {
            monoq.tail--;
            if (monoq.tail < 0) monoq.tail += monoq.capacity;
            monoq.size--;
        }

        while (!deque_is_empty(&monoq) && P[y] >= P[deque_get_front(&monoq)] + k) {
            int frontIndex = deque_pop_front(&monoq);
            ans = ans < (y - frontIndex) ? ans : (y - frontIndex);
        }

        deque_push_back(&monoq, y);
    }

    deque_free(&monoq);
    free(P);
    return ans < n + 1 ? ans : -1;
}

int main() {
    int nums1[] = {1};
    printf("%d
", shortestSubarray(nums1, 1, 1)); // Output: 1

    int nums2[] = {1, 2};
    printf("%d
", shortestSubarray(nums2, 2, 4)); // Output: -1

    int nums3[] = {2, -1, 2};
    printf("%d
", shortestSubarray(nums3, 3, 3)); // Output: 3

    return 0;
}