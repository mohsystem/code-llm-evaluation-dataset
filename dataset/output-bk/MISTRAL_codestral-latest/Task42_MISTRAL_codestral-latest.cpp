// C++
#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> users;

void registerUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    users[username] = password;
}

void login() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (users.find(username) != users.end() && users[username] == password) {
        std::cout << "Login successful
";
    } else {
        std::cout << "Invalid username or password
";
    }
}

int main() {
    int choice;

    while (true) {
        std::cout << "1. Register
2. Login
3. Exit
";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                exit(0);
            default:
                std::cout << "Invalid choice
";
        }
    }

    return 0;
}