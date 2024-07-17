#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);
    std::reverse(inputString.begin(), inputString.end());
    std::cout << "Reversed string is: " << inputString;
    return 0;
}