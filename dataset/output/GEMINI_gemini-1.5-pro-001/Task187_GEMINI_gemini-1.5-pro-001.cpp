#include <mutex>
#include <condition_variable>
#include <thread>

class H2O {
public:
    H2O() : hCount(0), oCount(0) {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return (hCount < 2 && oCount == 0) || (hCount == 2 && oCount == 1); });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        hCount++;
        if (hCount == 2 && oCount == 1) {
            hCount = 0;
            oCount = 0;
        }
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return hCount == 2 && oCount == 0; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        oCount++;
        cv.notify_all();
    }

private:
    mutex m;
    condition_variable cv;
    int hCount;
    int oCount;
};