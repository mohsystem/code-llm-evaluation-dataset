#include <iostream>

int main() {
    // Allocate memory
    int* ptr = new int;

    // Use the allocated memory (optional)
    *ptr = 10;

    // Deallocate memory
    delete ptr;

    return 0;
}