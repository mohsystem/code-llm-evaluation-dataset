#include <chrono>
#include <iostream>

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = start_time.time_since_epoch();
    std::cout << "Current processor time in seconds: " << elapsed_seconds.count() << std::endl;
    return 0;
}