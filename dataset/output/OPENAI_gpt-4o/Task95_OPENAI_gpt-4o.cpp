#include <iostream>
#include <ctime>

int main() {
    std::clock_t start = std::clock();
    // Simulate some processing time
    for (volatile int i = 0; i < 100000000; ++i);
    std::clock_t end = std::clock();
    double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "CPU time in seconds (C++): " << cpu_time << std::endl;
    return 0;
}