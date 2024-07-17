#include <pthread.h>
#include <stdio.h>

typedef struct {
    int n;
    int count;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int zeroTurn;
    int evenTurn;
    int oddTurn;
} ZeroEvenOdd;

void* zero(void* arg) {
    ZeroEvenOdd* zeroEvenOdd = (ZeroEvenOdd*)arg;
    for (int i = 0; i < zeroEvenOdd->n * 2; i++) {
        pthread_mutex_lock(&zeroEvenOdd->mutex);
        while (!zeroEvenOdd->zeroTurn) {
            pthread_cond_wait(&zeroEvenOdd->cond, &zeroEvenOdd->mutex);
        }
        printf("0");
        zeroEvenOdd->count++;
        if (zeroEvenOdd->count % 2 == 0) {
            zeroEvenOdd->zeroTurn = 0;
            zeroEvenOdd->evenTurn = 1;
        } else {
            zeroEvenOdd->zeroTurn = 0;
            zeroEvenOdd->oddTurn = 1;
        }
        pthread_cond_broadcast(&zeroEvenOdd->cond);
        pthread_mutex_unlock(&zeroEvenOdd->mutex);
    }
    return NULL;
}

void* even(void* arg) {
    ZeroEvenOdd* zeroEvenOdd = (ZeroEvenOdd*)arg;
    for (int i = 2; i <= zeroEvenOdd->n * 2; i += 2) {
        pthread_mutex_lock(&zeroEvenOdd->mutex);
        while (!zeroEvenOdd->evenTurn) {
            pthread_cond_wait(&zeroEvenOdd->cond, &zeroEvenOdd->mutex);
        }
        printf("%d", i);
        zeroEvenOdd->evenTurn = 0;
        zeroEvenOdd->zeroTurn = 1;
        pthread_cond_broadcast(&zeroEvenOdd->cond);
        pthread_mutex_unlock(&zeroEvenOdd->mutex);
    }
    return NULL;
}

void* odd(void* arg) {
    ZeroEvenOdd* zeroEvenOdd = (ZeroEvenOdd*)arg;
    for (int i = 1; i <= zeroEvenOdd->n * 2; i += 2) {
        pthread_mutex_lock(&zeroEvenOdd->mutex);
        while (!zeroEvenOdd->oddTurn) {
            pthread_cond_wait(&zeroEvenOdd->cond, &zeroEvenOdd->mutex);
        }
        printf("%d", i);
        zeroEvenOdd->oddTurn = 0;
        zeroEvenOdd->zeroTurn = 1;
        pthread_cond_broadcast(&zeroEvenOdd->cond);
        pthread_mutex_unlock(&zeroEvenOdd->mutex);
    }
    return NULL;
}

int main() {
    ZeroEvenOdd zeroEvenOdd = {5, 0, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 1, 0, 0};
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, zero, &zeroEvenOdd);
    pthread_create(&t2, NULL, even, &zeroEvenOdd);
    pthread_create(&t3, NULL, odd, &zeroEvenOdd);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}