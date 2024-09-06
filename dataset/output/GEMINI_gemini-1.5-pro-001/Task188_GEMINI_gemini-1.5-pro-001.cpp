#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooTurn;

public:
    FooBar(int n) : n(n), fooTurn(true) {}

    void foo() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return fooTurn; });
            cout << "foo";
            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar() {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return !fooTurn; });
            cout << "bar";
            fooTurn = true;
            cv.notify_one();
        }
    }
};

int main() {
    int n = 2;
    FooBar fooBar(n);
    thread threadA(&FooBar::foo, &fooBar);
    thread threadB(&FooBar::bar, &fooBar);
    threadA.join();
    threadB.join();
    return 0;
}