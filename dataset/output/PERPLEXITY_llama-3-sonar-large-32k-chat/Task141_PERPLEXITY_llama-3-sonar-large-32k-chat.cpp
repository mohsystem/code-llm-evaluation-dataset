#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);
    std::string reversed = std::string(s.rbegin(), s.rend());
    std::cout << "Reversed string: " << reversed << std::endl;
    return 0;
}