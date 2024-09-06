// CPP
#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> users = {{"user1", "password1"}, {"user2", "password2"}};

int main() {
    std::string username, password;

    std::cout << "Enter your username: ";
    std::cin >> username;

    std::cout << "Enter your password: ";
    std::cin >> password;

    if (users.find(username) != users.end() && users[username] == password) {
        std::cout << "Authentication successful." << std::endl;
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }

    return 0;
}