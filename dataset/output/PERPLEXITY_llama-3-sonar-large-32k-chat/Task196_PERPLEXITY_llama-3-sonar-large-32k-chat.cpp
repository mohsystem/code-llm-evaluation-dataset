#include <condition_variable>
#include <mutex>

class ZeroEvenOdd {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    int state = 0;

public:
    ZeroEvenOdd(int n) : n(n) {}

    void zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n * 2; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return state % 2 == 0; });
            printNumber(0);
            state++;
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for (int i = 2; i <= n * 2; i += 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this, i] { return state == i; });
            printNumber(i);
            state++;
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n * 2; i += 2) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this, i] { return state == i; });
            printNumber(i);
            state++;
            cv.notify_all();
        }
    }
};