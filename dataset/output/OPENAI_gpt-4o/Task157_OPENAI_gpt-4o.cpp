#include <iostream>

int main() {
    // Allocate memory for an integer
    int* int_ptr = new int(10);
    std::cout << "Value at allocated memory: " << *int_ptr << std::endl;

    // Deallocate memory
    delete int_ptr;

    return 0;
}