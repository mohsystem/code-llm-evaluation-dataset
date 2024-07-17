#include <semaphore.h>
#include <pthread.h>

typedef struct {
    sem_t hydrogen_semaphore;
    sem_t oxygen_semaphore;
    pthread_mutex_t mutex;
    pthread_cond_t cv;
    int count;
} H2O;

H2O* H2OCreate() {
    H2O* obj = (H2O*) malloc(sizeof(H2O));
    sem_init(&obj->hydrogen_semaphore, 0, 2);
    sem_init(&obj->oxygen_semaphore, 0, 1);
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cv, NULL);
    obj->count = 0;
    return obj;
}

void hydrogen(H2O* obj, void (*releaseHydrogen)()) {
    sem_wait(&obj->hydrogen_semaphore);

    pthread_mutex_lock(&obj->mutex);
    obj->count++;
    pthread_cond_broadcast(&obj->cv);
    while (obj->count < 3) {
        pthread_cond_wait(&obj->cv, &obj->mutex);
    }

    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();

    obj->count--;
    pthread_cond_broadcast(&obj->cv);
    pthread_mutex_unlock(&obj->mutex);
    sem_post(&obj->oxygen_semaphore);
}

void oxygen(H2O* obj, void (*releaseOxygen)()) {
    sem_wait(&obj->oxygen_semaphore);

    pthread_mutex_lock(&obj->mutex);
    obj->count++;
    pthread_cond_broadcast(&obj->cv);
    while (obj->count < 3) {
        pthread_cond_wait(&obj->cv, &obj->mutex);
    }

    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();

    obj->count--;
    pthread_cond_broadcast(&obj->cv);
    pthread_mutex_unlock(&obj->mutex);
    sem_post(&obj->hydrogen_semaphore);
    sem_post(&obj->hydrogen_semaphore);
}

void H2ODestroy(H2O* obj) {
    sem_destroy(&obj->hydrogen_semaphore);
    sem_destroy(&obj->oxygen_semaphore);
    pthread_mutex_destroy(&obj->mutex);
    pthread_cond_destroy(&obj->cv);
    free(obj);
}