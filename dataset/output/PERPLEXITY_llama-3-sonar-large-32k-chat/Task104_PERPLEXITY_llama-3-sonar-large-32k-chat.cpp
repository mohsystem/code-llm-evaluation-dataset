#include <iostream>
#include <string>

int main() {
    char buffer[10];
    std::cout << "Enter a string: ";
    std::cin.getline(buffer, 10);
    std::cout << "Buffer contents: " << buffer << std::endl;
    return 0;
}