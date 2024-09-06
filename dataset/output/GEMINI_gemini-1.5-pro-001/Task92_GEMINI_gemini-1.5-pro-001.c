#include <stdio.h>
#include <pthread.h>

int currentCounter = 0;
const int maxCounter = 5;
pthread_mutex_t mtx;

void* access_resource(void* thread_id) {
    if (currentCounter <= maxCounter) {
        pthread_mutex_lock(&mtx);
        if (currentCounter < maxCounter) {
            currentCounter++;
            printf("Thread %d is accessing currentCounter: %d\n", *((int*)thread_id), currentCounter);
        }
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    int thread_ids[10];
    pthread_mutex_init(&mtx, NULL);

    for (int i = 0; i < 10; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, access_resource, (void*)&thread_ids[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mtx);
    return 0;
}