#include <iostream>

int main() {
    // Allocate memory for an integer
    int* myVar = new int(42);
    std::cout << "C++: Value = " << *myVar << std::endl;

    // Deallocate memory
    delete myVar;

    return 0;
}