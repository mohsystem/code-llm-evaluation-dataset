
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

const int maxCounter = 10;
int currentCounter = 0;
std::mutex mtx;

void counterThread() {
    while (true) {
        if (currentCounter <= maxCounter) {
            std::lock_guard<std::mutex> lock(mtx);
            if (currentCounter <= maxCounter) {
                currentCounter++;
                std::cout << "Thread " << std::this_thread::get_id() << " accessing counter: " << currentCounter << std::endl;
            }
        } else {
            break;
        }
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 5; i++) {
        threads.emplace_back(counterThread);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
