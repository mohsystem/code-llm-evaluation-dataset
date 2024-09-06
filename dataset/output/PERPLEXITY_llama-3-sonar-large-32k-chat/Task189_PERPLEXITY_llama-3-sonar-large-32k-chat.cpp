#include <thread>
#include <mutex>
#include <condition_variable>

class ZeroEvenOdd {
private:
    int n;
    int state;
    std::mutex lock;
    std::condition_variable cond;

public:
    ZeroEvenOdd(int n) : n(n), state(0) {}

    void zero(std::function<void(int)> printNumber) {
        for (int i = 0; i < n * 2; i++) {
            std::unique_lock<std::mutex> lk(lock);
            cond.wait(lk, [this] { return state % 3 == 0; });
            printNumber(0);
            state++;
            lk.unlock();
            cond.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for (int i = 2; i <= n * 2; i += 2) {
            std::unique_lock<std::mutex> lk(lock);
            cond.wait(lk, [this] { return state % 3 == 1; });
            printNumber(i);
            state++;
            lk.unlock();
            cond.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n * 2; i += 2) {
            std::unique_lock<std::mutex> lk(lock);
            cond.wait(lk, [this] { return state % 3 == 2; });
            printNumber(i);
            state++;
            lk.unlock();
            cond.notify_all();
        }
    }
};