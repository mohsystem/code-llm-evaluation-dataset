#include <iostream>
#include <string>

std::string encryptString(const std::string& inputString, int key) {
    std::string encryptedString;
    for (char c : inputString) {
        if (std::isalpha(c)) {
            int asciiOffset = std::isupper(c) ? 65 : 97;
            encryptedString += static_cast<char>((c - asciiOffset + key) % 26 + asciiOffset);
        } else {
            encryptedString += c;
        }
    }
    return encryptedString;
}

int main() {
    std::string inputString = "HELLO WORLD";
    int key = 3;
    std::string encryptedString = encryptString(inputString, key);
    std::cout << encryptedString << std::endl;
    return 0;
}