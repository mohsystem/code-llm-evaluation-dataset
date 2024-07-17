#include <iostream>
#include <string>

void redirectUser() {
    std::string userInput;
    std::cout << "Enter 'google' to go to Google, 'facebook' to go to Facebook, or 'exit' to exit: ";
    std::cin >> userInput;
    if (userInput == "google") {
        std::cout << "Redirecting to Google...
";
    } else if (userInput == "facebook") {
        std::cout << "Redirecting to Facebook...
";
    } else if (userInput == "exit") {
        std::cout << "Exiting...
";
    } else {
        std::cout << "Invalid input. Please try again.
";
        redirectUser();
    }
}

int main() {
    redirectUser();
    return 0;
}