
#include <iostream>
#include <string>
#include <limits>

bool authenticate() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    return (username == "admin" && password == "password123");
}

void access_resource(const std::string& resource) {
    if (resource == "1") {
        std::cout << "Accessing confidential files..." << std::endl;
    } else if (resource == "2") {
        std::cout << "Accessing financial records..." << std::endl;
    } else if (resource == "3") {
        std::cout << "Accessing employee database..." << std::endl;
    } else {
        std::cout << "Invalid resource selection." << std::endl;
    }
}

int main() {
    if (authenticate()) {
        std::cout << "Authentication successful." << std::endl;
        std::string choice;
        while (true) {
            std::cout << "\\nAvailable resources:" << std::endl;
            std::cout << "1. Confidential files" << std::endl;
            std::cout << "2. Financial records" << std::endl;
            std::cout << "3. Employee database" << std::endl;
            std::cout << "4. Exit" << std::endl;
            std::cout << "Enter resource number to access (or 4 to exit): ";
            std::cin >> choice;
            if (choice == "4") {
                break;
            }
            access_resource(choice);
        }
    } else {
        std::cout << "Authentication failed. Access denied." << std::endl;
    }
    return 0;
}
