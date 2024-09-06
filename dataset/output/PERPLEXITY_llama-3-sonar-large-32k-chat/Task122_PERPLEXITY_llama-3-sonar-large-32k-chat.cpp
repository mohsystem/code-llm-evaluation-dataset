#include <iostream>
#include <map>
#include <string>

class User {
public:
    std::string username;
    std::string password;

    User(std::string username, std::string password) {
        this->username = username;
        this->password = password;
    }
};

std::map<std::string, User> users;

void signup() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    users[username] = User(username, password);
    std::cout << "Signup successful!" << std::endl;
}

int main() {
    while (true) {
        std::cout << "1. Signup" << std::endl;
        std::cout << "2. Exit" << std::endl;
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice == 1) {
            signup();
        } else if (choice == 2) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}