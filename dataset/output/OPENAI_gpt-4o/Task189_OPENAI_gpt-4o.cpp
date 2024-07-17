#include <iostream>
#include <thread>
#include <functional>
#include <semaphore.h>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    sem_t zeroSem, evenSem, oddSem;

public:
    ZeroEvenOdd(int n) : n(n) {
        sem_init(&zeroSem, 0, 1);
        sem_init(&evenSem, 0, 0);
        sem_init(&oddSem, 0, 0);
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            sem_wait(&zeroSem);
            printNumber(0);
            if (i % 2 == 0) {
                sem_post(&oddSem);
            } else {
                sem_post(&evenSem);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&evenSem);
            printNumber(i);
            sem_post(&zeroSem);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&oddSem);
            printNumber(i);
            sem_post(&zeroSem);
        }
    }
};

void printNumber(int x) {
    cout << x;
}

int main() {
    ZeroEvenOdd zeo(5);

    thread threadA(&ZeroEvenOdd::zero, &zeo, printNumber);
    thread threadB(&ZeroEvenOdd::even, &zeo, printNumber);
    thread threadC(&ZeroEvenOdd::odd, &zeo, printNumber);

    threadA.join();
    threadB.join();
    threadC.join();

    return 0;
}