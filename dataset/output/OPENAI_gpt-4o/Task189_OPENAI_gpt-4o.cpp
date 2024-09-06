#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int state;
    mutex mtx;
    condition_variable cv;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        state = 0;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]{ return state == 0; });
            printNumber(0);
            state = (i % 2 == 1) ? 1 : 2;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]{ return state == 2; });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]{ return state == 1; });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }
};

void printNumber(int x) {
    cout << x;
}

int main() {
    ZeroEvenOdd zeroEvenOdd(5);

    thread threadA(&ZeroEvenOdd::zero, &zeroEvenOdd, printNumber);
    thread threadB(&ZeroEvenOdd::even, &zeroEvenOdd, printNumber);
    thread threadC(&ZeroEvenOdd::odd, &zeroEvenOdd, printNumber);

    threadA.join();
    threadB.join();
    threadC.join();

    return 0;
}