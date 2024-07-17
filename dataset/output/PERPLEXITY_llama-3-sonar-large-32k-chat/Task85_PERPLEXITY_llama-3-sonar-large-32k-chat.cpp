#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generateRandomString(int length) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string str;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < length; i++) {
        str += alphabet[rand() % alphabet.length()];
    }
    return str;
}

int main() {
    std::string str = generateRandomString(10);
    std::cout << str << std::endl;
    return 0;
}