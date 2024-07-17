// C++
#include <iostream>
#include <string>

std::string encrypt(std::string message, int key) {
    for (char &c : message) {
        c += key;
    }
    return message;
}

int main() {
    std::string message;
    int key;
    std::cout << "Enter the message: ";
    std::getline(std::cin, message);
    std::cout << "Enter the secret key: ";
    std::cin >> key;
    std::string encryptedMessage = encrypt(message, key);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    return 0;
}