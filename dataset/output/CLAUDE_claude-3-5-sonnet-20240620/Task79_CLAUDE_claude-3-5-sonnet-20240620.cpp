
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

std::string encrypt_message(const std::string& message, int key) {
    std::vector<char> cipher;
    for (char c = 'A'; c <= 'Z'; ++c) {
        cipher.push_back(c);
    }
    
    std::mt19937 gen(key);
    std::shuffle(cipher.begin(), cipher.end(), gen);
    
    std::string encrypted;
    for (char c : message) {
        if (std::isalpha(c)) {
            int index = std::toupper(c) - 'A';
            encrypted += cipher[index];
        } else {
            encrypted += c;
        }
    }
    
    return encrypted;
}

int main() {
    std::string message = "Hello, World!";
    int key = 42;
    std::string encrypted = encrypt_message(message, key);
    std::cout << "Original: " << message << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    return 0;
}
