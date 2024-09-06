#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct H2O {
    sem_t hydrogen_semaphore;
    sem_t oxygen_semaphore;
    pthread_barrier_t barrier;
} H2O;

void init(H2O* h2o) {
    sem_init(&h2o->hydrogen_semaphore, 0, 2);
    sem_init(&h2o->oxygen_semaphore, 0, 0);
    pthread_barrier_init(&h2o->barrier, NULL, 3);
}

void* hydrogen(void* arg) {
    H2O* h2o = (H2O*)arg;
    sem_wait(&h2o->hydrogen_semaphore);
    pthread_barrier_wait(&h2o->barrier);
    printf("H");
    sem_post(&h2o->hydrogen_semaphore);
    sem_post(&h2o->oxygen_semaphore);
    return NULL;
}

void* oxygen(void* arg) {
    H2O* h2o = (H2O*)arg;
    sem_wait(&h2o->oxygen_semaphore);
    pthread_barrier_wait(&h2o->barrier);
    printf("O");
    return NULL;
}

int main() {
    H2O h2o;
    init(&h2o);
    char water[] = "HOH";
    pthread_t threads[sizeof(water) - 1];

    for (size_t i = 0; i < sizeof(water) - 1; i++) {
        if (water[i] == 'H') {
            pthread_create(&threads[i], NULL, hydrogen, &h2o);
        } else {
            pthread_create(&threads[i], NULL, oxygen, &h2o);
        }
    }

    for (size_t i = 0; i < sizeof(water) - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&h2o.hydrogen_semaphore);
    sem_destroy(&h2o.oxygen_semaphore);
    pthread_barrier_destroy(&h2o.barrier);

    return 0;
}