#include <iostream>
#include <limits>

int main() {
    int cppNum;
    std::cout << "Enter a number for C++: ";
    std::cin >> cppNum;
    
    if(std::cin.fail()) {
        std::cin.clear(); // clear input buffer to restore cin to a usable state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
        std::cerr << "Invalid input in C++" << std::endl;
    } else {
        std::cout << "C++ read the number: " << cppNum << std::endl;
    }
    
    return 0;
}