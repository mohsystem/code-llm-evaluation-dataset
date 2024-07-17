#include <stdio.h>
#include <pthread.h>

int currentCounter = 0;
int maxCounter = 10;
pthread_mutex_t lock;

void *accessResource(void *threadId) {
    int id = *(int *)threadId;
    if (currentCounter <= maxCounter) {
        pthread_mutex_lock(&lock);
        currentCounter++;
        printf("Thread %d is accessing the currentCounter at the moment. Current counter value: %d
", id, currentCounter);
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[20];
    pthread_mutex_init(&lock, NULL);
    int threadIds[20];

    for (int i = 0; i < 20; i++) {
        threadIds[i] = i + 1;
        pthread_create(&threads[i], NULL, accessResource, &threadIds[i]);
    }

    for (int i = 0; i < 20; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}