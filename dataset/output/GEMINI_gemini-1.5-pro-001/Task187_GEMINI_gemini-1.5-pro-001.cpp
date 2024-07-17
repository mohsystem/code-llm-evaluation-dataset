#include <semaphore.h>
#include <thread>
#include <mutex>
#include <condition_variable>

class H2O {
private:
    sem_t hydrogen_semaphore;
    sem_t oxygen_semaphore;
    std::mutex mutex;
    std::condition_variable cv;
    int count;

public:
    H2O() : count(0) {
        sem_init(&hydrogen_semaphore, 0, 2);
        sem_init(&oxygen_semaphore, 0, 1);
    }

    ~H2O() {
        sem_destroy(&hydrogen_semaphore);
        sem_destroy(&oxygen_semaphore);
    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        sem_wait(&hydrogen_semaphore);

        std::unique_lock<std::mutex> lock(mutex);
        count++;
        cv.notify_all();
        while (count < 3) {
            cv.wait(lock);
        }

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        count--;
        cv.notify_all();
        sem_post(&oxygen_semaphore);
    }

    void oxygen(std::function<void()> releaseOxygen) {
        sem_wait(&oxygen_semaphore);

        std::unique_lock<std::mutex> lock(mutex);
        count++;
        cv.notify_all();
        while (count < 3) {
            cv.wait(lock);
        }

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        count--;
        cv.notify_all();
        sem_post(&hydrogen_semaphore);
        sem_post(&hydrogen_semaphore);
    }
};