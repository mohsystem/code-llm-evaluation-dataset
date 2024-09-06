#include <stdio.h>
#include <pthread.h>

typedef struct {
    int n;
    int counter;
    pthread_mutex_t mutex;
    pthread_cond_t zeroCond;
    pthread_cond_t evenOddCond;
    int zeroTurn;
} ZeroEvenOdd;

void printNumber(int x) {
    printf("%d", x);
}

void* zero(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) arg;
    for (int i = 0; i < obj->n; ++i) {
        pthread_mutex_lock(&obj->mutex);
        while (!obj->zeroTurn) {
            pthread_cond_wait(&obj->zeroCond, &obj->mutex);
        }
        printNumber(0);
        obj->zeroTurn = 0;
        pthread_cond_signal(&obj->evenOddCond);
        pthread_mutex_unlock(&obj->mutex);
    }
    return NULL;
}

void* even(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) arg;
    for (int i = 2; i <= obj->n; i += 2) {
        pthread_mutex_lock(&obj->mutex);
        while (obj->zeroTurn || obj->counter % 2 != 0) {
            pthread_cond_wait(&obj->evenOddCond, &obj->mutex);
        }
        printNumber(obj->counter++);
        obj->zeroTurn = 1;
        pthread_cond_signal(&obj->zeroCond);
        pthread_mutex_unlock(&obj->mutex);
    }
    return NULL;
}

void* odd(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) arg;
    for (int i = 1; i <= obj->n; i += 2) {
        pthread_mutex_lock(&obj->mutex);
        while (obj->zeroTurn || obj->counter % 2 == 0) {
            pthread_cond_wait(&obj->evenOddCond, &obj->mutex);
        }
        printNumber(obj->counter++);
        obj->zeroTurn = 1;
        pthread_cond_signal(&obj->zeroCond);
        pthread_mutex_unlock(&obj->mutex);
    }
    return NULL;
}

int main() {
    ZeroEvenOdd obj;
    obj.n = 5;
    obj.counter = 1;
    obj.zeroTurn = 1;
    pthread_mutex_init(&obj.mutex, NULL);
    pthread_cond_init(&obj.zeroCond, NULL);
    pthread_cond_init(&obj.evenOddCond, NULL);

    pthread_t threadA, threadB, threadC;
    pthread_create(&threadA, NULL, zero, &obj);
    pthread_create(&threadB, NULL, even, &obj);
    pthread_create(&threadC, NULL, odd, &obj);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    pthread_mutex_destroy(&obj.mutex);
    pthread_cond_destroy(&obj.zeroCond);
    pthread_cond_destroy(&obj.evenOddCond);
    return 0;
}