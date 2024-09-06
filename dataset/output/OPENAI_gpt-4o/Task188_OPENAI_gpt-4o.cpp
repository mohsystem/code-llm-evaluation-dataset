#include <iostream>
#include <thread>
#include <condition_variable>

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool fooTurn;

public:
    FooBar(int n) : n(n), fooTurn(true) {}

    void foo() {
        for (int i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return fooTurn; });
            std::cout << "foo";
            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar() {
        for (int i = 0; i < n; ++i) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return !fooTurn; });
            std::cout << "bar";
            fooTurn = true;
            cv.notify_one();
        }
    }
};

int main() {
    int n = 2;
    FooBar fooBar(n);
    std::thread threadA(&FooBar::foo, &fooBar);
    std::thread threadB(&FooBar::bar, &fooBar);
    threadA.join();
    threadB.join();
    return 0;
}