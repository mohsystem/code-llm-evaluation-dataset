#include <iostream>

int performOperation(int input);

int main() {
    int userInput;
    std::cout << "Enter an integer: ";
    if (std::cin >> userInput) {
        int result = performOperation(userInput);
        std::cout << "The result from C++ operation is: " << result << std::endl;
    } else {
        std::cout << "Invalid input." << std::endl;
    }
    return 0;
}

int performOperation(int input) {
    return input * 2;
}