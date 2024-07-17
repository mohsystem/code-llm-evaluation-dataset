#include <pthread.h>

typedef struct {
    int hydrogenCount;
    int oxygenCount;
    pthread_mutex_t lock;
    pthread_cond_t cv;
} H2O;

void* hydrogen(void* arg) {
    H2O* h2o = (H2O*)arg;
    pthread_mutex_lock(&h2o->lock);
    h2o->hydrogenCount++;
    if (h2o->hydrogenCount == 2) {
        pthread_cond_broadcast(&h2o->cv);
    } else {
        pthread_cond_wait(&h2o->cv, &h2o->lock);
    }
    pthread_mutex_unlock(&h2o->lock);
    // releaseHydrogen();
    pthread_mutex_lock(&h2o->lock);
    h2o->hydrogenCount--;
    pthread_mutex_unlock(&h2o->lock);
    return NULL;
}

void* oxygen(void* arg) {
    H2O* h2o = (H2O*)arg;
    pthread_mutex_lock(&h2o->lock);
    h2o->oxygenCount++;
    if (h2o->oxygenCount == 1) {
        pthread_cond_broadcast(&h2o->cv);
    } else {
        pthread_cond_wait(&h2o->cv, &h2o->lock);
    }
    pthread_mutex_unlock(&h2o->lock);
    // releaseOxygen();
    pthread_mutex_lock(&h2o->lock);
    h2o->oxygenCount--;
    pthread_mutex_unlock(&h2o->lock);
    return NULL;
}