// C++
#include <iostream>
#include <cctype>

std::string encrypt(const std::string& message, int key) {
    std::string cipher;
    for (char character : message) {
        if (std::isalpha(character)) {
            char shifted = std::isupper(character) ? 'A' : 'a';
            cipher += (char) ((character - shifted + key) % 26 + shifted);
        } else {
            cipher += character;
        }
    }
    return cipher;
}

int main() {
    std::string message = "HELLO WORLD";
    int key = 3;
    std::string encryptedMessage = encrypt(message, key);
    std::cout << encryptedMessage << std::endl;
    return 0;
}