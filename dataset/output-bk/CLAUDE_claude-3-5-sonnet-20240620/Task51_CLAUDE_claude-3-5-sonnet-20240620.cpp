
#include <iostream>
#include <string>

std::string encrypt(std::string text, int shift) {
    for (char &c : text) {
        if (std::isalpha(c)) {
            char base = std::isupper(c) ? \'A\' : \'a\';
            c = (c - base + shift) % 26 + base;
        }
    }
    return text;
}

int main() {
    std::string text;
    int shift;

    std::cout << "Enter a string to encrypt: ";
    std::getline(std::cin, text);

    std::cout << "Enter the shift value: ";
    std::cin >> shift;

    std::string encrypted = encrypt(text, shift);
    std::cout << "Encrypted string: " << encrypted << std::endl;

    return 0;
}
