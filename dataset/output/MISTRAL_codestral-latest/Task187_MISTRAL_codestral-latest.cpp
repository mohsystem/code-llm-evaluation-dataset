#include <semaphore.h>

class H2O {
private:
    sem_t hSem;
    sem_t oSem;

public:
    H2O() {
        sem_init(&hSem, 0, 2);
        sem_init(&oSem, 0, 0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&hSem);
        releaseHydrogen();
        sem_post(&oSem);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&oSem);
        sem_wait(&oSem);
        releaseOxygen();
        sem_post(&hSem);
        sem_post(&hSem);
    }
};