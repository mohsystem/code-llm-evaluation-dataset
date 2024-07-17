code here:
#include <iostream>

int main() {
    int* ptr = new int(10);
    std::cout << *ptr << std::endl;  // prints 10

    delete ptr;
    ptr = new int(20);
    std::cout << *ptr << std::endl;  // prints 20

    delete ptr;
    return 0;
}