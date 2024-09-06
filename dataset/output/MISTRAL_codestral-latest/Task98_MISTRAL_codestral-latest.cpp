// C++
#include <iostream>

int main() {
    int userInput;
    std::cout << "Enter a number: ";
    if (std::cin >> userInput) {
        std::cout << "You entered: " << userInput << std::endl;
    } else {
        std::cout << "Invalid input. Please enter an integer." << std::endl;
    }
    return 0;
}