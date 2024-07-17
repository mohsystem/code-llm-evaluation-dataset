#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter user role (admin/user/guest): ";
    std::getline(std::cin, input);

    for (char &c : input) {
        c = tolower(c);
    }

    if (input == "admin") {
        std::cout << "Redirecting to admin page...
";
    } else if (input == "user") {
        std::cout << "Redirecting to user page...
";
    } else if (input == "guest") {
        std::cout << "Redirecting to guest page...
";
    } else {
        std::cout << "Invalid role!
";
    }

    return 0;
}