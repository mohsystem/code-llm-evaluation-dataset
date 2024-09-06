code here:
#include <iostream>
#include <map>
#include <string>

std::map<char, char> createCipher(int key) {
    std::map<char, char> cipher;
    for (int i = 0; i < 26; i++) {
        cipher[(char) (65 + i)] = (char) (65 + (i + key) % 26);
        cipher[(char) (97 + i)] = (char) (97 + (i + key) % 26);
    }
    return cipher;
}

std::string encryptMessage(std::string message, int key) {
    std::map<char, char> cipher = createCipher(key);
    std::string encryptedMessage;
    for (char c : message) {
        if (cipher.find(c) != cipher.end()) {
            encryptedMessage += cipher[c];
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

int main() {
    int key = 3;
    std::string message = "Hello, World!";
    std::cout << "Original Message: " << message << std::endl;
    std::cout << "Encrypted Message: " << encryptMessage(message, key) << std::endl;
    return 0;
}