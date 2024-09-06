#include <semaphore.h>
#include <pthread.h>

typedef struct {
    sem_t hSem;
    sem_t oSem;
} H2O;

H2O* H2O_create() {
    H2O* obj = (H2O*)malloc(sizeof(H2O));
    sem_init(&obj->hSem, 0, 2);
    sem_init(&obj->oSem, 0, 0);
    return obj;
}

void hydrogen(H2O* obj, void (*releaseHydrogen)()) {
    sem_wait(&obj->hSem);
    releaseHydrogen();
    sem_post(&obj->oSem);
}

void oxygen(H2O* obj, void (*releaseOxygen)()) {
    sem_wait(&obj->oSem);
    sem_wait(&obj->oSem);
    releaseOxygen();
    sem_post(&obj->hSem);
    sem_post(&obj->hSem);
}