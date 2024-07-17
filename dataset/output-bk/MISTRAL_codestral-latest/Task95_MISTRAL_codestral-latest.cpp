// C++
#include <chrono>
#include <iostream>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    double time_spent = std::chrono::duration<double>(end - start).count();
    std::cout << "Current processor time: " << time_spent << " seconds" << std::endl;
    return 0;
}