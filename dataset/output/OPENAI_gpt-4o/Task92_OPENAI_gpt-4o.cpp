#include <iostream>
#include <thread>
#include <mutex>

int maxCounter = 10;
int currentCounter = 0;
std::mutex counterMutex;

void worker(int thread_id) {
    while (true) {
        std::lock_guard<std::mutex> lock(counterMutex);
        if (currentCounter <= maxCounter) {
            std::cout << "Thread " << thread_id << " accessing currentCounter: " << currentCounter << std::endl;
            currentCounter++;
        } else {
            break;
        }
    }
}

int main() {
    std::thread threads[5];
    
    for (int i = 0; i < 5; ++i) {
        threads[i] = std::thread(worker, i);
    }
    
    for (int i = 0; i < 5; ++i) {
        threads[i].join();
    }
    
    return 0;
}