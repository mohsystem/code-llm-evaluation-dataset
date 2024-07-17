
#include <iostream>
#include <string>
#include <limits>

int getValidNumber(int min, int max) {
    int number;
    while (true) {
        std::cout << "Enter a number between " << min << " and " << max << ": ";
        if (std::cin >> number && number >= min && number <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), \'\
\');
            return number;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), \'\
\');
            std::cout << "Invalid input. ";
        }
    }
}

std::string getValidString(int maxLength) {
    std::string input;
    while (true) {
        std::cout << "Enter your name (max " << maxLength << " characters): ";
        std::getline(std::cin, input);
        if (!input.empty() && input.length() <= maxLength) {
            return input;
        } else {
            std::cout << "Invalid input. ";
        }
    }
}

int main() {
    int number = getValidNumber(1, 100);
    std::string name = getValidString(50);

    std::cout << "Hello, " << name << "!" << std::endl;
    std::cout << "Your number squared is: " << (number * number) << std::endl;
    std::cout << "Your number cubed is: " << (number * number * number) << std::endl;

    return 0;
}
