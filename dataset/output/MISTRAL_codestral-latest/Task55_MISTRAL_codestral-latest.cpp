#include <iostream>
#include <regex>

int main() {
    std::string email;
    std::cout << "Enter your email: ";
    std::cin >> email;

    const std::regex emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\."
                               "[a-zA-Z0-9_+&*-]+)*@"
                               "(?:[a-zA-Z0-9-]+\\.)+[a-z"
                               "A-Z]{2,7}$");

    if (std::regex_match(email, emailRegex)) {
        std::cout << "Valid email address
";
    } else {
        std::cout << "Invalid email address
";
    }

    return 0;
}