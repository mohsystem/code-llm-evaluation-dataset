#include <iostream>

int main() {
    // Allocate memory
    int* array = new int[1024];

    // Use memory (example)
    array[0] = 10;

    // Deallocate memory
    delete[] array;

    return 0;
}