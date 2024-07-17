#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class FooBar {
private:
    int n;
    bool foo_done;
    std::mutex mtx;
    std::condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        foo_done = false;
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            printFoo();
            foo_done = true;
            cv.notify_all();
            cv.wait(lock, [this]() { return !foo_done; });
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]() { return foo_done; });
            printBar();
            foo_done = false;
            cv.notify_all();
        }
    }
};

int main() {
    FooBar fb(2); // change `n` value as needed

    auto printFoo = []() { std::cout << "foo"; };
    auto printBar = []() { std::cout << "bar"; };

    std::thread threadA(&FooBar::foo, &fb, printFoo);
    std::thread threadB(&FooBar::bar, &fb, printBar);

    threadA.join();
    threadB.join();

    return 0;
}