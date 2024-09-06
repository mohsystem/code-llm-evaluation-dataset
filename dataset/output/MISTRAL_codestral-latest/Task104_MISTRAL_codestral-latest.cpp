// C++
#include <iostream>
#include <string>

int main() {
    const int bufferSize = 10;
    std::string userInput;
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);
    if (userInput.length() > bufferSize) {
        userInput = userInput.substr(0, bufferSize);
    }
    std::cout << "Truncated input: " << userInput;
    return 0;
}