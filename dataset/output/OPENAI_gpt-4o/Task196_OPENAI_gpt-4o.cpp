#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    bool zero_turn = true;
    bool even_turn = false;
    mutex mtx;
    condition_variable zero_cv, even_cv, odd_cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(void(*printNumber)(int)) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            zero_cv.wait(lock, [this]() { return zero_turn; });
            printNumber(0);
            zero_turn = false;
            if (i % 2 == 0) {
                odd_cv.notify_one();
            }
            else {
                even_cv.notify_one();
            }
        }
    }

    void even(void(*printNumber)(int)) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            even_cv.wait(lock, [this]() { return !zero_turn && even_turn; });
            printNumber(i);
            even_turn = false;
            zero_turn = true;
            zero_cv.notify_one();
        }
    }

    void odd(void(*printNumber)(int)) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);
            odd_cv.wait(lock, [this]() { return !zero_turn && !even_turn; });
            printNumber(i);
            even_turn = true;
            zero_turn = true;
            zero_cv.notify_one();
        }
    }
};

void printNumber(int x) {
    cout << x;
}

int main() {
    int n = 5;
    ZeroEvenOdd zeroEvenOdd(n);

    thread t1([&]() { zeroEvenOdd.zero(printNumber); });
    thread t2([&]() { zeroEvenOdd.even(printNumber); });
    thread t3([&]() { zeroEvenOdd.odd(printNumber); });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}