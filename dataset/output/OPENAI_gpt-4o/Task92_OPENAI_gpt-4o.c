#include <stdio.h>
#include <pthread.h>

#define MAX_COUNTER 10

int currentCounter = 0;
pthread_mutex_t lock;

void* worker(void* thread_id) {
    int tid = *((int*) thread_id);
    free(thread_id);

    while (1) {
        pthread_mutex_lock(&lock);
        if (currentCounter <= MAX_COUNTER) {
            printf("Thread %d accessing currentCounter: %d\n", tid, currentCounter);
            currentCounter++;
        } else {
            pthread_mutex_unlock(&lock);
            break;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 5; ++i) {
        int* thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, worker, thread_id);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}