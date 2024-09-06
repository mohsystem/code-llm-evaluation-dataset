code here:
#include <iostream>
#include <string>

int main() {
    std::string userInput;
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);
    std::cout << "You entered: " << userInput << std::endl;
    return 0;
}