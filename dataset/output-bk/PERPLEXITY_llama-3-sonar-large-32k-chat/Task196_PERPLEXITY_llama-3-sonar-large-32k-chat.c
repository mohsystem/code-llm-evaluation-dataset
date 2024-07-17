#include <pthread.h>
#include <stdio.h>

typedef struct {
    int n;
    pthread_mutex_t mtx;
    pthread_cond_t cv;
    int state;
} ZeroEvenOdd;

void* zero(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    for (int i = 0; i < obj->n * 2; i++) {
        pthread_mutex_lock(&obj->mtx);
        while (obj->state % 2 != 0) {
            pthread_cond_wait(&obj->cv, &obj->mtx);
        }
        printf("0");
        fflush(stdout);
        obj->state++;
        pthread_cond_broadcast(&obj->cv);
        pthread_mutex_unlock(&obj->mtx);
    }
    return NULL;
}

void* even(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    for (int i = 2; i <= obj->n * 2; i += 2) {
        pthread_mutex_lock(&obj->mtx);
        while (obj->state != i) {
            pthread_cond_wait(&obj->cv, &obj->mtx);
        }
        printf("%d", i);
        fflush(stdout);
        obj->state++;
        pthread_cond_broadcast(&obj->cv);
        pthread_mutex_unlock(&obj->mtx);
    }
    return NULL;
}

void* odd(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    for (int i = 1; i <= obj->n * 2; i += 2) {
        pthread_mutex_lock(&obj->mtx);
        while (obj->state != i) {
            pthread_cond_wait(&obj->cv, &obj->mtx);
        }
        printf("%d", i);
        fflush(stdout);
        obj->state++;
        pthread_cond_broadcast(&obj->cv);
        pthread_mutex_unlock(&obj->mtx);
    }
    return NULL;
}

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    pthread_mutex_init(&obj->mtx, NULL);
    pthread_cond_init(&obj->cv, NULL);
    obj->state = 0;
    return obj;
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {
    pthread_mutex_destroy(&obj->mtx);
    pthread_cond_destroy(&obj->cv);
    free(obj);
}