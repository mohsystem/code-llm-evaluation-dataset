#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string generateRandomString(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string result;
    std::srand(std::time(0));

    for (int i = 0; i < length; ++i) {
        result += characters[std::rand() % characters.length()];
    }
    return result;
}

int main() {
    std::cout << generateRandomString(10) << std::endl;
    return 0;
}