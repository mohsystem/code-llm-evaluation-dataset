// C++ code
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> users;
    users["admin"] = "password";
    users["user"] = "password";

    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (users.find(username) != users.end() && users[username] == password) {
        std::cout << "Authentication successful!" << std::endl;
    } else {
        std::cout << "Invalid username or password" << std::endl;
    }
    return 0;
}