#include <semaphore.h>
#include <iostream>

class FooBar {
private:
    int n;
    sem_t fooSemaphore;
    sem_t barSemaphore;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&fooSemaphore, 0, 1);
        sem_init(&barSemaphore, 0, 0);
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&fooSemaphore);
            printFoo();
            sem_post(&barSemaphore);
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&barSemaphore);
            printBar();
            sem_post(&fooSemaphore);
        }
    }
};