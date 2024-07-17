#include <iostream>
#include <string>

void redirectUser(std::string input) {
    if (input == "home") {
        std::cout << "Redirecting to home page..." << std::endl;
    } else if (input == "about") {
        std::cout << "Redirecting to about page..." << std::endl;
    } else if (input == "contact") {
        std::cout << "Redirecting to contact page..." << std::endl;
    } else {
        std::cout << "Invalid input. Staying on current page." << std::endl;
    }
}

int main() {
    std::string input;
    std::cout << "Enter a page: ";
    std::getline(std::cin, input);

    redirectUser(input);

    return 0;
}