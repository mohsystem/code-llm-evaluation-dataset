#include <functional>
#include <semaphore.h>

class ZeroEvenOdd {
private:
    int n;
    sem_t zeroSemaphore;
    sem_t evenSemaphore;
    sem_t oddSemaphore;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&zeroSemaphore, 0, 1);
        sem_init(&evenSemaphore, 0, 0);
        sem_init(&oddSemaphore, 0, 0);
    }

    void zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            sem_wait(&zeroSemaphore);
            printNumber(0);
            if (i % 2 == 0) {
                sem_post(&oddSemaphore);
            } else {
                sem_post(&evenSemaphore);
            }
        }
    }

    void even(std::function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&evenSemaphore);
            printNumber(i);
            sem_post(&zeroSemaphore);
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&oddSemaphore);
            printNumber(i);
            sem_post(&zeroSemaphore);
        }
    }
};