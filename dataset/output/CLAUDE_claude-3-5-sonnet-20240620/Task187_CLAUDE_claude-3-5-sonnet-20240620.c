
#include <semaphore.h>
#include <pthread.h>

typedef struct {
    sem_t hydrogen_sem;
    sem_t oxygen_sem;
    pthread_barrier_t barrier;
} H2O;

void init(H2O* h2o) {
    sem_init(&h2o->hydrogen_sem, 0, 2);
    sem_init(&h2o->oxygen_sem, 0, 1);
    pthread_barrier_init(&h2o->barrier, NULL, 3);
}

void hydrogen(H2O* h2o, void (*releaseHydrogen)()) {
    sem_wait(&h2o->hydrogen_sem);
    pthread_barrier_wait(&h2o->barrier);
    releaseHydrogen();
    sem_post(&h2o->hydrogen_sem);
}

void oxygen(H2O* h2o, void (*releaseOxygen)()) {
    sem_wait(&h2o->oxygen_sem);
    pthread_barrier_wait(&h2o->barrier);
    releaseOxygen();
    sem_post(&h2o->oxygen_sem);
}
