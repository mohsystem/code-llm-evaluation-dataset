#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

std::string generateRandomString() {
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string randomString;
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 10; i++) {
        randomString += chars[rand() % chars.length()];
    }
    return randomString;
}

std::string toUnicode(const std::string& str) {
    std::string unicodeString;
    for (char c : str) {
        unicodeString += "\\u";
        unicodeString += std::to_string(static_cast<unsigned int>(c));
        unicodeString += " ";
    }
    return unicodeString;
}

void writeToFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath, std::ios::out | std::ios::trunc);
    file.imbue(std::locale("en_US.UTF-8"));
    file << content;
}

int main() {
    std::string filePath = "tempXXXXXX.txt";
    for (char& c : filePath) {
        if (c == 'X') {
            c = 'A' + rand() % 26;
        }
    }
    std::string randomString = generateRandomString();
    std::string unicodeString = toUnicode(randomString);
    writeToFile(filePath, unicodeString);
    std::cout << filePath << std::endl;
    return 0;
}