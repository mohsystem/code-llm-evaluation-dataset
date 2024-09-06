#include <condition_variable>
#include <mutex>

class H2O {
private:
    int hydrogenCount = 0;
    int oxygenCount = 0;
    std::mutex hydrogenMutex;
    std::mutex oxygenMutex;
    std::condition_variable hydrogenCond;
    std::condition_variable oxygenCond;

public:
    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(hydrogenMutex);
        hydrogenCount++;
        while (hydrogenCount < 2 || oxygenCount < 1) {
            hydrogenCond.wait(lock);
        }
        releaseHydrogen();
        hydrogenCount--;
        if (hydrogenCount == 0) {
            oxygenCond.notify_all();
        }
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(oxygenMutex);
        oxygenCount++;
        while (oxygenCount < 1 || hydrogenCount < 2) {
            oxygenCond.wait(lock);
        }
        releaseOxygen();
        oxygenCount--;
        if (oxygenCount == 0) {
            hydrogenCond.notify_all();
        }
    }
};