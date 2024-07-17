
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool fooTurn;

public:
    FooBar(int n) {
        this->n = n;
        fooTurn = true;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return fooTurn; });
            printFoo();
            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return !fooTurn; });
            printBar();
            fooTurn = true;
            cv.notify_one();
        }
    }
};

int main() {
    int n = 2;
    FooBar fooBar(n);

    auto printFoo = []() { std::cout << "foo"; };
    auto printBar = []() { std::cout << "bar"; };

    std::thread t1(&FooBar::foo, &fooBar, printFoo);
    std::thread t2(&FooBar::bar, &fooBar, printBar);

    t1.join();
    t2.join();

    return 0;
}
