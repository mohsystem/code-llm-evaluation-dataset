
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class ZeroEvenOdd {
private:
    int n;
    int current;
    std::mutex mtx;
    std::condition_variable cv;
    int turn;

public:
    ZeroEvenOdd(int n) : n(n), current(1), turn(0) {}

    void zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return turn == 0; });
            printNumber(0);
            turn = (current % 2 == 0) ? 2 : 1;
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return turn == 2; });
            printNumber(current);
            current++;
            turn = 0;
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return turn == 1; });
            printNumber(current);
            current++;
            turn = 0;
            cv.notify_all();
        }
    }
};

void printNumber(int x) {
    std::cout << x;
}

int main() {
    int n = 5;
    ZeroEvenOdd zeo(n);

    std::thread threadA(&ZeroEvenOdd::zero, &zeo, printNumber);
    std::thread threadB(&ZeroEvenOdd::even, &zeo, printNumber);
    std::thread threadC(&ZeroEvenOdd::odd, &zeo, printNumber);

    threadA.join();
    threadB.join();
    threadC.join();

    return 0;
}
