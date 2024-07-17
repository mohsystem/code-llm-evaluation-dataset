// C++

#include <iostream>
#include <string>

bool authenticateUser(const std::string& username, const std::string& password) {
    // This is a simple example. In a real-world application,
    // you would check the username and password against a database.
    if (username == "admin" && password == "password") {
        return true;
    } else {
        return false;
    }
}

int main() {
    std::string username, password;

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    if (authenticateUser(username, password)) {
        std::cout << "Authentication successful.
";
    } else {
        std::cout << "Authentication failed.
";
    }

    return 0;
}