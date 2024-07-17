
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_COUNTER 10
#define NUM_THREADS 5

int currentCounter = 0;
pthread_mutex_t lock;

void* counterThread(void* arg) {
    while (true) {
        if (currentCounter <= MAX_COUNTER) {
            pthread_mutex_lock(&lock);
            if (currentCounter <= MAX_COUNTER) {
                currentCounter++;
                printf("Thread %ld accessing counter: %d\
", (long)pthread_self(), currentCounter);
            }
            pthread_mutex_unlock(&lock);
        } else {
            break;
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, counterThread, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
