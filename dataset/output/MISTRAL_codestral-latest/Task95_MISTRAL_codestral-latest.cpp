#include <iostream>
#include <ctime>

int main() {
    clock_t start = clock();
    // Your code here
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Processor time: " << duration << " seconds" << std::endl;
    return 0;
}