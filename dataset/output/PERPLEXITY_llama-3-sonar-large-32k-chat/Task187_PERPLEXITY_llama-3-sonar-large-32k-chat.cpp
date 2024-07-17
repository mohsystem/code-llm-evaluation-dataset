class H2O {
private:
    int hydrogenCount = 0;
    int oxygenCount = 0;
    std::mutex lock;
    std::condition_variable cv;

public:
    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lk(lock);
        hydrogenCount++;
        if (hydrogenCount == 2) {
            cv.notify_all();
        } else {
            cv.wait(lk);
        }
        lk.unlock();
        releaseHydrogen();
        lk.lock();
        hydrogenCount--;
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lk(lock);
        oxygenCount++;
        if (oxygenCount == 1) {
            cv.notify_all();
        } else {
            cv.wait(lk);
        }
        lk.unlock();
        releaseOxygen();
        lk.lock();
        oxygenCount--;
    }
};