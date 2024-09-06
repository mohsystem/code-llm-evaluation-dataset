#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct {
    int n;
    sem_t zeroSemaphore;
    sem_t evenSemaphore;
    sem_t oddSemaphore;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    sem_init(&obj->zeroSemaphore, 0, 1);
    sem_init(&obj->evenSemaphore, 0, 0);
    sem_init(&obj->oddSemaphore, 0, 0);
    return obj;
}

void zero(ZeroEvenOdd* obj, void (*printNumber)(int)) {
    for (int i = 0; i < obj->n; i++) {
        sem_wait(&obj->zeroSemaphore);
        printNumber(0);
        if (i % 2 == 0) {
            sem_post(&obj->oddSemaphore);
        } else {
            sem_post(&obj->evenSemaphore);
        }
    }
}

void even(ZeroEvenOdd* obj, void (*printNumber)(int)) {
    for (int i = 2; i <= obj->n; i += 2) {
        sem_wait(&obj->evenSemaphore);
        printNumber(i);
        sem_post(&obj->zeroSemaphore);
    }
}

void odd(ZeroEvenOdd* obj, void (*printNumber)(int)) {
    for (int i = 1; i <= obj->n; i += 2) {
        sem_wait(&obj->oddSemaphore);
        printNumber(i);
        sem_post(&obj->zeroSemaphore);
    }
}