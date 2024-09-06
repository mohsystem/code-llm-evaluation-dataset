#include <chrono>
#include <iostream>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(start.time_since_epoch());
    std::cout << "Current processor time in seconds: " << duration.count() << std::endl;
    return 0;
}