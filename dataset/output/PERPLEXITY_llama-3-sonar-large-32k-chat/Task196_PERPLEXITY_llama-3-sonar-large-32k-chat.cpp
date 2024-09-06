#include <condition_variable>
#include <mutex>

class ZeroEvenOdd {
private:
    int n;
    bool zeroTurn = true;
    bool evenTurn = false;
    bool oddTurn = false;
    int count = 0;
    std::mutex mtx;
    std::condition_variable cv;

public:
    ZeroEvenOdd(int n) : n(n) {}

    void zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n * 2; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return zeroTurn; });
            printNumber(0);
            count++;
            if (count % 2 == 0) {
                zeroTurn = false;
                evenTurn = true;
            } else {
                zeroTurn = false;
                oddTurn = true;
            }
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for (int i = 2; i <= n * 2; i += 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return evenTurn; });
            printNumber(i);
            evenTurn = false;
            zeroTurn = true;
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n * 2; i += 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return oddTurn; });
            printNumber(i);
            oddTurn = false;
            zeroTurn = true;
            cv.notify_all();
        }
    }
};