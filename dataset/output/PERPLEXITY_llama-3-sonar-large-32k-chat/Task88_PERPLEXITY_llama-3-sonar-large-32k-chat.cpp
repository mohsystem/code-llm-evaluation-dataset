#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string getRandomString() {
    std::string SALTCHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string salt;
    srand(time(0));
    while (salt.length() < 10) {
        salt += SALTCHARS[rand() % SALTCHARS.length()];
    }
    return salt;
}

std::string toUnicode(const std::string& str) {
    std::string unicodeString;
    for (char c : str) {
        unicodeString += "\\u";
        unicodeString += std::to_string(static_cast<int>(c));
    }
    return unicodeString;
}

int main() {
    std::string randomString = getRandomString();
    std::string unicodeString = toUnicode(randomString);
    std::string tempFileName = "temp_" + getRandomString() + ".txt";
    std::ofstream tempFile(tempFileName, std::ios::out | std::ios::binary);
    tempFile.imbue(std::locale("en_US.UTF-8"));
    tempFile << unicodeString;
    tempFile.close();
    std::cout << tempFileName << std::endl;
    return 0;
}