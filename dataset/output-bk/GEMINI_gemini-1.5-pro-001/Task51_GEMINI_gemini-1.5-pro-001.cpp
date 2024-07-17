#include <iostream>
#include <string>

std::string encrypt(const std::string& message);

int main() {
    std::string message;
    std::cout << "Enter a string to encrypt: ";
    std::getline(std::cin, message);

    std::string encryptedMessage = encrypt(message);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;

    return 0;
}

std::string encrypt(const std::string& message) {
    std::string encrypted = "";
    for (char c : message) {
        encrypted += (char)(c + 3); // Simple Caesar cipher with a shift of 3
    }
    return encrypted;
}