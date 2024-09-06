#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class H2O {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int hydrogen_count{0};

public:
    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return hydrogen_count < 2; });
        releaseHydrogen();
        hydrogen_count++;
        if (hydrogen_count == 2) {
            cv.notify_all();
        }
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&] { return hydrogen_count == 2; });
        releaseOxygen();
        hydrogen_count = 0;
        cv.notify_all();
    }
};

// Simulation
void releaseHydrogen() {
    std::cout << "H";
}

void releaseOxygen() {
    std::cout << "O";
}

int main() {
    H2O h2o;
    std::string water = "HOH";
    std::thread threads[water.length()];

    for (size_t i = 0; i < water.length(); ++i) {
        if (water[i] == 'H') {
            threads[i] = std::thread(&H2O::hydrogen, &h2o, releaseHydrogen);
        } else {
            threads[i] = std::thread(&H2O::oxygen, &h2o, releaseOxygen);
        }
    }

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}