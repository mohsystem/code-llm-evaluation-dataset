#include <stdio.h>
#include <pthread.h>

#define MAX_COUNTER 10

int currentCounter = 0;
pthread_mutex_t lock;

void* check_and_increment(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        if (currentCounter <= MAX_COUNTER) {
            printf("Thread-%d accessing currentCounter: %d
", *(int*)arg, currentCounter);
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
    int thread_ids[5];
    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, check_and_increment, &thread_ids[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}