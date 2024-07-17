#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

typedef void (*printNumber)(int);

typedef struct {
    int n;
    bool zero_turn;
    bool even_turn;
    pthread_mutex_t mtx;
    pthread_cond_t zero_cv;
    pthread_cond_t even_cv;
    pthread_cond_t odd_cv;
} ZeroEvenOdd;

void zero(ZeroEvenOdd* obj, printNumber printNumber) {
    for (int i = 0; i < obj->n; ++i) {
        pthread_mutex_lock(&obj->mtx);
        while (!obj->zero_turn) {
            pthread_cond_wait(&obj->zero_cv, &obj->mtx);
        }
        printNumber(0);
        obj->zero_turn = false;
        if (i % 2 == 0) {
            pthread_cond_signal(&obj->odd_cv);
        } else {
            pthread_cond_signal(&obj->even_cv);
        }
        pthread_mutex_unlock(&obj->mtx);
    }
}

void even(ZeroEvenOdd* obj, printNumber printNumber) {
    for (int i = 2; i <= obj->n; i += 2) {
        pthread_mutex_lock(&obj->mtx);
        while (obj->zero_turn || !obj->even_turn) {
            pthread_cond_wait(&obj->even_cv, &obj->mtx);
        }
        printNumber(i);
        obj->even_turn = false;
        obj->zero_turn = true;
        pthread_cond_signal(&obj->zero_cv);
        pthread_mutex_unlock(&obj->mtx);
    }
}

void odd(ZeroEvenOdd* obj, printNumber printNumber) {
    for (int i = 1; i <= obj->n; i += 2) {
        pthread_mutex_lock(&obj->mtx);
        while (obj->zero_turn || obj->even_turn) {
            pthread_cond_wait(&obj->odd_cv, &obj->mtx);
        }
        printNumber(i);
        obj->even_turn = true;
        obj->zero_turn = true;
        pthread_cond_signal(&obj->zero_cv);
        pthread_mutex_unlock(&obj->mtx);
    }
}

void* zero_thread(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    zero(obj, putchar);
    return NULL;
}

void* even_thread(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    even(obj, putchar);
    return NULL;
}

void* odd_thread(void* arg) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*)arg;
    odd(obj, putchar);
    return NULL;
}

int main() {
    ZeroEvenOdd obj;
    obj.n = 5;
    obj.zero_turn = true;
    obj.even_turn = false;
    pthread_mutex_init(&obj.mtx, NULL);
    pthread_cond_init(&obj.zero_cv, NULL);
    pthread_cond_init(&obj.even_cv, NULL);
    pthread_cond_init(&obj.odd_cv, NULL);

    pthread_t threads[3];
    pthread_create(&threads[0], NULL, zero_thread, &obj);
    pthread_create(&threads[1], NULL, even_thread, &obj);
    pthread_create(&threads[2], NULL, odd_thread, &obj);

    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&obj.mtx);
    pthread_cond_destroy(&obj.zero_cv);
    pthread_cond_destroy(&obj.even_cv);
    pthread_cond_destroy(&obj.odd_cv);

    return 0;
}