#include <iostream>
#include <thread>
#include <mutex>

int currentCounter = 0;
int maxCounter = 10;
std::mutex lock;

void accessResource(int threadId) {
    if (currentCounter <= maxCounter) {
        lock.lock();
        currentCounter++;
        std::cout << "Thread " << threadId << " is accessing the currentCounter at the moment. Current counter value: " << currentCounter << std::endl;
        lock.unlock();
    }
}

int main() {
    std::thread threads[20];

    for (int i = 0; i < 20; i++) {
        threads[i] = std::thread(accessResource, i + 1);
    }

    for (int i = 0; i < 20; i++) {
        threads[i].join();
    }

    return 0;
}