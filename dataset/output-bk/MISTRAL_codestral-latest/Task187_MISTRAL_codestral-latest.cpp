#include <semaphore.h>
#include <mutex>

class H2O {
private:
    sem_t hydrogen;
    sem_t oxygen;
    std::mutex lock;

public:
    H2O() {
        sem_init(&hydrogen, 0, 2);
        sem_init(&oxygen, 0, 0);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&hydrogen);
        lock.lock();
        releaseHydrogen();
        sem_post(&oxygen);
        lock.unlock();
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&oxygen);
        sem_wait(&oxygen);
        lock.lock();
        releaseOxygen();
        sem_post(&hydrogen);
        sem_post(&hydrogen);
        lock.unlock();
    }
};