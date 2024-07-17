
#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout.precision(9);
    std::cout << "Current processor time: " << std::fixed << elapsed.count() << " seconds" << std::endl;
    return 0;
}
