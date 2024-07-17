#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int currentCounter = 0;
int maxCounter = 5;

void* accessResource(void* arg) {
    int threadId = *(int*)arg;
    while (currentCounter <= maxCounter) {
        pthread_mutex_lock(&lock);
        currentCounter++;
        printf("Thread %d is accessing the currentCounter: %d
", threadId, currentCounter);
        pthread_mutex_unlock(&lock);
        usleep(100000); // simulate some work
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int threadId1 = 1, threadId2 = 2;
    pthread_create(&thread1, NULL, accessResource, &threadId1);
    pthread_create(&thread2, NULL, accessResource, &threadId2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}