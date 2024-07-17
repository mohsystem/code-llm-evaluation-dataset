#include <semaphore.h>
#include <functional>
#include <mutex>

class H2O {
private:
    sem_t hSemaphore;
    sem_t oSemaphore;
    std::mutex mtx;
    int hCount = 0;

public:
    H2O() {
        sem_init(&hSemaphore, 0, 2);
        sem_init(&oSemaphore, 0, 0);
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        sem_wait(&hSemaphore);
        releaseHydrogen();
        std::unique_lock<std::mutex> lock(mtx);
        hCount++;
        if (hCount == 2) {
            hCount = 0;
            sem_post(&oSemaphore);
        }
    }

    void oxygen(std::function<void()> releaseOxygen) {
        sem_wait(&oSemaphore);
        releaseOxygen();
        sem_post(&hSemaphore);
        sem_post(&hSemaphore);
    }
};