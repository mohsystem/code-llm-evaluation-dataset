#include <iostream>
#include <thread>
#include <mutex>

class Counter {
private:
    int maxCounter;
    int currentCounter;
    std::mutex lock;

public:
    Counter(int maxCounter) : maxCounter(maxCounter), currentCounter(0) {}

    void accessResource(int threadId) {
        std::lock_guard<std::mutex> guard(lock);
        if (currentCounter <= maxCounter) {
            currentCounter++;
            std::cout << "Thread " << threadId << " is accessing the currentCounter at the moment." << std::endl;
        }
    }
};

int main() {
    int maxCounter = 10;
    Counter counter(maxCounter);

    // Create and start multiple threads
    std::thread threads[15];
    for (int i = 0; i < 15; i++) {
        threads[i] = std::thread(&Counter::accessResource, &counter, i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 15; i++) {
        threads[i].join();
    }

    return 0;
}