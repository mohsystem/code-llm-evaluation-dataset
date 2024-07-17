#include <semaphore.h>
#include <pthread.h>

typedef struct {
    sem_t hydrogen;
    sem_t oxygen;
    pthread_mutex_t lock;
} H2O;

H2O* H2O_create() {
    H2O* obj = malloc(sizeof(H2O));
    sem_init(&obj->hydrogen, 0, 2);
    sem_init(&obj->oxygen, 0, 0);
    pthread_mutex_init(&obj->lock, NULL);
    return obj;
}

void hydrogen(H2O* obj, void (*releaseHydrogen)()) {
    sem_wait(&obj->hydrogen);
    pthread_mutex_lock(&obj->lock);
    releaseHydrogen();
    sem_post(&obj->oxygen);
    pthread_mutex_unlock(&obj->lock);
}

void oxygen(H2O* obj, void (*releaseOxygen)()) {
    sem_wait(&obj->oxygen);
    sem_wait(&obj->oxygen);
    pthread_mutex_lock(&obj->lock);
    releaseOxygen();
    sem_post(&obj->hydrogen);
    sem_post(&obj->hydrogen);
    pthread_mutex_unlock(&obj->lock);
}