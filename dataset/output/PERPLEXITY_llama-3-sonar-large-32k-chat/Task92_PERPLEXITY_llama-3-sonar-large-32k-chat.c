#include <stdio.h>
#include <pthread.h>

int maxCounter = 5;
int currentCounter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* accessResource(void* arg) {
    int threadId = *(int*)arg;
    while (currentCounter <= maxCounter) {
        pthread_mutex_lock(&lock);
        if (currentCounter <= maxCounter) {
            currentCounter++;
            printf("Thread %d is accessing the currentCounter at %d\n", threadId, currentCounter);
        } else {
            break;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    int threadIds[5];
    for (int i = 0; i < 5; i++) {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, accessResource, &threadIds[i]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}