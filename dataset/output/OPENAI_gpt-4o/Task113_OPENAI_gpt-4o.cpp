#include <iostream>
#include <string>

int main() {
    std::string inputStr1, inputStr2, result;
    std::cout << "Enter first string: ";
    std::getline(std::cin, inputStr1);
    std::cout << "Enter second string: ";
    std::getline(std::cin, inputStr2);
    result = inputStr1 + inputStr2;
    std::cout << "Concatenated result: " << result << std::endl;
    return 0;
}