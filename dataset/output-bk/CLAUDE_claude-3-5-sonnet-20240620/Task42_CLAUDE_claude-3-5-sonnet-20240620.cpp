
#include <iostream>
#include <string>
#include <unordered_map>
#include <openssl/sha.h>
#include <vector>

class UserAuthentication {
private:
    std::unordered_map<std::string, std::vector<unsigned char>> users;

    std::vector<unsigned char> hashPassword(const std::string& password) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, password.c_str(), password.length());
        SHA256_Final(hash, &sha256);
        return std::vector<unsigned char>(hash, hash + SHA256_DIGEST_LENGTH);
    }

public:
    void registerUser() {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;

        if (users.find(username) != users.end()) {
            std::cout << "Username already exists. Please choose another." << std::endl;
            return;
        }

        std::cout << "Enter password: ";
        std::cin >> password;

        users[username] = hashPassword(password);
        std::cout << "Registration successful." << std::endl;
    }

    void login() {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        auto it = users.find(username);
        if (it != users.end() && it->second == hashPassword(password)) {
            std::cout << "Login successful." << std::endl;
        } else {
            std::cout << "Invalid username or password." << std::endl;
        }
    }
};

int main() {
    UserAuthentication auth;
    int choice;

    while (true) {
        std::cout << "1. Register" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                auth.registerUser();
                break;
            case 2:
                auth.login();
                break;
            case 3:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}
