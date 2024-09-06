
#include <semaphore.h>
#include <pthread.h>
#include <functional>

class H2O {
private:
    sem_t hydrogen_sem;
    sem_t oxygen_sem;
    pthread_barrier_t barrier;

public:
    H2O() {
        sem_init(&hydrogen_sem, 0, 2);
        sem_init(&oxygen_sem, 0, 1);
        pthread_barrier_init(&barrier, NULL, 3);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&hydrogen_sem);
        pthread_barrier_wait(&barrier);
        releaseHydrogen();
        sem_post(&hydrogen_sem);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&oxygen_sem);
        pthread_barrier_wait(&barrier);
        releaseOxygen();
        sem_post(&oxygen_sem);
    }
};
