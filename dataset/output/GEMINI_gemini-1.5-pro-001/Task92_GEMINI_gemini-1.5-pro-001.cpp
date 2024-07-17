#include <iostream>
#include <thread>
#include <mutex>

int currentCounter = 0;
int maxCounter;
std::mutex mtx;

void accessResource(int threadId) {
    if (currentCounter <= maxCounter) {
        mtx.lock();
        if (currentCounter <= maxCounter) {
            currentCounter++;
            std::cout << "Thread " << threadId << " is accessing currentCounter: " << currentCounter << std::endl;
        }
        mtx.unlock();
    }
}

int main() {
    maxCounter = 5;
    std::thread thread1(accessResource, 1);
    std::thread thread2(accessResource, 2);

    thread1.join();
    thread2.join();

    return 0;
}