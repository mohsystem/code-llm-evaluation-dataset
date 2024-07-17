#include <pthread.h>
#include <semaphore.h>

typedef void (*releaseFn)();

sem_t hSemaphore;
sem_t oSemaphore;
pthread_mutex_t mutex;
int hCount = 0;

void H2O_init() {
    sem_init(&hSemaphore, 0, 2);
    sem_init(&oSemaphore, 0, 0);
    pthread_mutex_init(&mutex, NULL);
}

void hydrogen(releaseFn releaseHydrogen) {
    sem_wait(&hSemaphore);
    releaseHydrogen();
    pthread_mutex_lock(&mutex);
    hCount++;
    if (hCount == 2) {
        hCount = 0;
        sem_post(&oSemaphore);
    }
    pthread_mutex_unlock(&mutex);
}

void oxygen(releaseFn releaseOxygen) {
    sem_wait(&oSemaphore);
    releaseOxygen();
    sem_post(&hSemaphore);
    sem_post(&hSemaphore);
}

void H2O_destroy() {
    sem_destroy(&hSemaphore);
    sem_destroy(&oSemaphore);
    pthread_mutex_destroy(&mutex);
}