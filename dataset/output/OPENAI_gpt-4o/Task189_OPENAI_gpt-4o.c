#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

typedef void (*printNumberFunc)(int);

typedef struct {
    int n;
    sem_t zeroSem, evenSem, oddSem;
} ZeroEvenOdd;

void printNumber(int x) {
    printf("%d", x);
}

void* zero(void* arg) {
    ZeroEvenOdd* zeo = (ZeroEvenOdd*)arg;
    for (int i = 0; i < zeo->n; i++) {
        sem_wait(&zeo->zeroSem);
        printNumber(0);
        if (i % 2 == 0) {
            sem_post(&zeo->oddSem);
        } else {
            sem_post(&zeo->evenSem);
        }
    }
    return NULL;
}

void* even(void* arg) {
    ZeroEvenOdd* zeo = (ZeroEvenOdd*)arg;
    for (int i = 2; i <= zeo->n; i += 2) {
        sem_wait(&zeo->evenSem);
        printNumber(i);
        sem_post(&zeo->zeroSem);
    }
    return NULL;
}

void* odd(void* arg) {
    ZeroEvenOdd* zeo = (ZeroEvenOdd*)arg;
    for (int i = 1; i <= zeo->n; i += 2) {
        sem_wait(&zeo->oddSem);
        printNumber(i);
        sem_post(&zeo->zeroSem);
    }
    return NULL;
}

int main() {
    ZeroEvenOdd zeo;
    zeo.n = 5;

    sem_init(&zeo.zeroSem, 0, 1);
    sem_init(&zeo.evenSem, 0, 0);
    sem_init(&zeo.oddSem, 0, 0);

    pthread_t threadA, threadB, threadC;

    pthread_create(&threadA, NULL, zero, &zeo);
    pthread_create(&threadB, NULL, even, &zeo);
    pthread_create(&threadC, NULL, odd, &zeo);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    return 0;
}