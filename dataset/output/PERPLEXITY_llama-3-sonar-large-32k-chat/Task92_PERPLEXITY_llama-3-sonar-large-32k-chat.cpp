#include <iostream>
#include <thread>
#include <mutex>

std::mutex lock;
int currentCounter = 0;
int maxCounter = 5;

void accessResource(int threadId) {
    while (currentCounter <= maxCounter) {
        std::lock_guard<std::mutex> guard(lock);
        currentCounter++;
        std::cout << "Thread " << threadId << " is accessing the currentCounter: " << currentCounter << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate some work
    }
}

int main() {
    std::thread thread1(accessResource, 1);
    std::thread thread2(accessResource, 2);
    thread1.join();
    thread2.join();
    return 0;
}