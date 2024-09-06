#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int counter;
    std::mutex m;
    std::condition_variable cv;
    bool zeroTurn;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        counter = 1;
        zeroTurn = true;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return zeroTurn; });
            printNumber(0);
            zeroTurn = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return !zeroTurn && counter % 2 == 0; });
            printNumber(counter++);
            zeroTurn = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this]() { return !zeroTurn && counter % 2 != 0; });
            printNumber(counter++);
            zeroTurn = true;
            cv.notify_all();
        }
    }
};

void printNumber(int x) {
    cout << x;
}

int main() {
    ZeroEvenOdd zeroEvenOdd(5);

    thread threadA([&]() { zeroEvenOdd.zero(printNumber); });
    thread threadB([&]() { zeroEvenOdd.even(printNumber); });
    thread threadC([&]() { zeroEvenOdd.odd(printNumber); });

    threadA.join();
    threadB.join();
    threadC.join();

    return 0;
}