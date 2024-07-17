// C++
#include <iostream>
#include <cstdlib>

int main() {
    // Allocate memory
    int size = 100;
    int* memory = new int[size];

    // Deallocate memory
    delete[] memory;

    return 0;
}