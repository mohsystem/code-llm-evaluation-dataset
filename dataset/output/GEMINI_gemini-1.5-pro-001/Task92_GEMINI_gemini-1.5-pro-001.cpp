#include <iostream>
#include <thread>
#include <mutex>

int currentCounter = 0;
const int maxCounter = 5;
std::mutex mtx;

void access_resource(int thread_id) {
    if (currentCounter <= maxCounter) {
        std::lock_guard<std::mutex> lock(mtx);
        if (currentCounter < maxCounter) {
            currentCounter++;
            std::cout << "Thread " << thread_id << " is accessing currentCounter: " << currentCounter << std::endl;
        }
    }
}

int main() {
    std::thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(access_resource, i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}