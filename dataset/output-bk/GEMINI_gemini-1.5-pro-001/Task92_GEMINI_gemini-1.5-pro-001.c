#include <stdio.h>
#include <pthread.h>

int currentCounter = 0;
int maxCounter;
pthread_mutex_t mutex;

void *accessResource(void *arg) {
    int threadId = *((int *)arg);
    if (currentCounter <= maxCounter) {
        pthread_mutex_lock(&mutex);
        if (currentCounter <= maxCounter) {
            currentCounter++;
            printf("Thread %d is accessing currentCounter: %d
", threadId, currentCounter);
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    maxCounter = 5;
    pthread_t thread1, thread2;
    int threadId1 = 1, threadId2 = 2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, accessResource, (void *)&threadId1);
    pthread_create(&thread2, NULL, accessResource, (void *)&threadId2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}