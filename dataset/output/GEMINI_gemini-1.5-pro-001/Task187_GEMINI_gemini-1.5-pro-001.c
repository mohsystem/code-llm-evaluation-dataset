#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int hCount;
    int oCount;
} H2O;

H2O* H2OCreate() {
    H2O* obj = (H2O*)malloc(sizeof(H2O));
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond, NULL);
    obj->hCount = 0;
    obj->oCount = 0;
    return obj;
}

void hydrogen(H2O* obj, void (*releaseHydrogen)()) {
    pthread_mutex_lock(&obj->mutex);
    while (!((obj->hCount < 2 && obj->oCount == 0) || (obj->hCount == 2 && obj->oCount == 1))) {
        pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    obj->hCount++;
    if (obj->hCount == 2 && obj->oCount == 1) {
        obj->hCount = 0;
        obj->oCount = 0;
    }
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mutex);
}

void oxygen(H2O* obj, void (*releaseOxygen)()) {
    pthread_mutex_lock(&obj->mutex);
    while (!(obj->hCount == 2 && obj->oCount == 0)) {
        pthread_cond_wait(&obj->cond, &obj->mutex);
    }
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    obj->oCount++;
    pthread_cond_broadcast(&obj->cond);
    pthread_mutex_unlock(&obj->mutex);
}

void H2ODestroy(H2O* obj) {
    pthread_mutex_destroy(&obj->mutex);
    pthread_cond_destroy(&obj->cond);
    free(obj);
}