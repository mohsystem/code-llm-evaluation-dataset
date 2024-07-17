
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int n;
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int turn;
} ZeroEvenOdd;

void ZeroEvenOdd_init(ZeroEvenOdd* obj, int n) {
    obj->n = n;
    obj->count = 1;
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond, NULL);
    obj->turn = 0;
}

void ZeroEvenOdd_free(ZeroEvenOdd* obj) {
    pthread_mutex_destroy(&obj->mutex);
    pthread_cond_destroy(&obj->cond);
}

void zero(ZeroEvenOdd* obj) {
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        while (obj->turn != 0) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }
        printf("0");
        obj->turn = (obj->count % 2 == 0) ? 2 : 1;
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void even(ZeroEvenOdd* obj) {
    for (int i = 0; i < obj->n / 2; i++) {
        pthread_mutex_lock(&obj->mutex);
        while (obj->turn != 2) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }
        printf("%d", obj->count);
        obj->count++;
        obj->turn = 0;
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void odd(ZeroEvenOdd* obj) {
    for (int i = 0; i < (obj->n + 1) / 2; i++) {
        pthread_mutex_lock(&obj->mutex);
        while (obj->turn != 1) {
            pthread_cond_wait(&obj->cond, &obj->mutex);
        }
        printf("%d", obj->count);
        obj->count++;
        obj->turn = 0;
        pthread_cond_broadcast(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void* thread_zero(void* arg) {
    zero((ZeroEvenOdd*)arg);
    return NULL;
}

void* thread_even(void* arg) {
    even((ZeroEvenOdd*)arg);
    return NULL;
}

void* thread_odd(void* arg) {
    odd((ZeroEvenOdd*)arg);
    return NULL;
}

int main() {
    int n = 5;
    ZeroEvenOdd zeo;
    ZeroEvenOdd_init(&zeo, n);

    pthread_t threadA, threadB, threadC;

    pthread_create(&threadA, NULL, thread_zero, &zeo);
    pthread_create(&threadB, NULL, thread_even, &zeo);
    pthread_create(&threadC, NULL, thread_odd, &zeo);

    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);

    ZeroEvenOdd_free(&zeo);

    printf("\
");  // New line at the end

    return 0;
}
