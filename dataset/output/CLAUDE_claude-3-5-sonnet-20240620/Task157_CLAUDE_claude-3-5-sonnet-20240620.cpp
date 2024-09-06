
#include <iostream>

int main() {
    // Allocate memory
    int* ptr = new int[10];

    // Use the memory
    ptr[0] = 5;
    std::cout << ptr[0] << std::endl;

    // Deallocate memory
    delete[] ptr;

    return 0;
}
