#include <iostream>
#include <string>

std::string encrypt(const std::string& text, int shift) {
    std::string result;

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char) ((c - base + shift) % 26 + base);
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    std::string text = "Hello, World!";
    int shift = 3;
    std::cout << "Text : " << text << std::endl;
    std::cout << "Shift : " << shift << std::endl;
    std::cout << "Cipher: " << encrypt(text, shift) << std::endl;
    return 0;
}