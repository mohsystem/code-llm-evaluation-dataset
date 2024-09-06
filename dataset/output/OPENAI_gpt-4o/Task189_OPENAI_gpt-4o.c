#include <stdio.h>
#include <pthread.h>

typedef struct {
    int n;
    int state;
    pthread_mutex_t lock;
    pthread_cond_t condition;
} ZeroEvenOdd;

void printNumber(int x) {
    printf("%d", x);
}

void* zero(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    for (int i = 1; i <= obj->n; i++) {
        pthread_mutex_lock(&obj->lock);
        while (obj->state != 0) {
            pthread_cond_wait(&obj->condition, &obj->lock);
        }
        printNumber(0);
        obj->state = (i % 2 == 1) ? 1 : 2;
        pthread_cond_broadcast(&obj->condition);
        pthread_mutex_unlock(&obj->lock);
    }
    return NULL;
}

void* even(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    for (int i = 2; i <= obj->n; i += 2) {
        pthread_mutex_lock(&obj->lock);
        while (obj->state != 2) {
            pthread_cond_wait(&obj->condition, &obj->lock);
        }
        printNumber(i);
        obj->state = 0;
        pthread_cond_broadcast(&obj->condition);
        pthread_mutex_unlock(&obj->lock);
    }
    return NULL;
}

void* odd(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    for (int i = 1; i <= obj->n; i += 2) {
        pthread_mutex_lock(&obj->lock);
        while (obj->state != 1) {
            pthread_cond_wait(&obj->condition, &obj->lock);
        }
        printNumber(i);
        obj->state = 0;
        pthread_cond_broadcast(&obj->condition);
        pthread_mutex_unlock(&obj->lock);
    }
    return NULL;
}

int main() {
    int n = 5;
    ZeroEvenOdd zeroEvenOdd = {n, 0, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER};

    pthread_t threadA, threadB, threadC;
    pthread_create(&threadA, NULL, zero, &zeroEvenOdd);
    pthread_create(&threadB, NULL, even, &zeroEvenOdd);
    pthread_create(&threadC, NULL, odd, &zeroEvenOdd);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    return 0;
}