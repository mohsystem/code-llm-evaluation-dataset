#include <iostream>
#include <string>

std::string encrypt(const std::string& str) {
    std::string encrypted;
    for (char c : str) {
        encrypted += (char) (c + 3);
    }
    return encrypted;
}

int main() {
    std::string str = "Hello, World!";
    std::cout << "Original: " << str << std::endl;
    std::string encrypted = encrypt(str);
    std::cout << "Encrypted: " << encrypted << std::endl;
    return 0;
}