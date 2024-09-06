
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

class SharedResource {
private:
    int currentCounter;
    const int maxCounter;
    std::mutex mtx;

public:
    SharedResource(int max) : currentCounter(0), maxCounter(max) {}

    bool accessResource(int threadId) {
        if (currentCounter <= maxCounter) {
            std::lock_guard<std::mutex> lock(mtx);
            if (currentCounter <= maxCounter) {
                currentCounter++;
                std::cout << "Thread " << threadId << " accessing. Current counter: " << currentCounter << std::endl;
                return currentCounter <= maxCounter;
            }
        }
        return false;
    }
};

void threadFunction(SharedResource& resource, int threadId) {
    while (resource.accessResource(threadId)) {
        // Continue accessing the resource
    }
}

int main() {
    const int maxCounter = 10;
    const int numThreads = 5;
    SharedResource sharedResource(maxCounter);

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(threadFunction, std::ref(sharedResource), i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
