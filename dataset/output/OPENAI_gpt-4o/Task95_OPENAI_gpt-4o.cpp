#include <iostream>
#include <ctime>

int main() {
    clock_t start = clock();
    // Do something here to use some CPU time
    clock_t end = clock();
    double processorTimeSeconds = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "C++: " << processorTimeSeconds << std::endl;
    return 0;
}