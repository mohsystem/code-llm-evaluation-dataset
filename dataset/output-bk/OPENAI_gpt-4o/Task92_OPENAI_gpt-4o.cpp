#include <iostream>
#include <thread>
#include <mutex>

const int maxCounter = 10;
int currentCounter = 0;
std::mutex mtx;

void check_and_increment(int threadID) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        if (currentCounter <= maxCounter) {
            std::cout << "Thread-" << threadID << " accessing currentCounter: " << currentCounter << std::endl;
            currentCounter++;
        } else {
            break;
        }
    }
}

int main() {
    const int threadCount = 5;
    std::thread threads[threadCount];
    for (int i = 0; i < threadCount; i++) {
        threads[i] = std::thread(check_and_increment, i + 1);
    }
    for (int i = 0; i < threadCount; i++) {
        threads[i].join();
    }
    return 0;
}