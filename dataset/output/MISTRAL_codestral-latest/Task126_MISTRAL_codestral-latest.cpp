// C++
#include <iostream>
#include <string>

int main() {
    std::string userInput;
    std::cout << "Enter your input: ";
    std::cin >> userInput;

    if (userInput == "home") {
        std::cout << "Redirecting to home page..." << std::endl;
    } else if (userInput == "about") {
        std::cout << "Redirecting to about page..." << std::endl;
    } else if (userInput == "contact") {
        std::cout << "Redirecting to contact page..." << std::endl;
    } else {
        std::cout << "Invalid input. Redirecting to default page..." << std::endl;
    }

    return 0;
}