#include <iostream>
#include <cstdlib>
#include <ctime>

std::string generateRandomString(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string randomString;
    randomString.reserve(length);

    std::srand(std::time(nullptr));
    for (int i = 0; i < length; i++) {
        randomString.push_back(characters[std::rand() % characters.length()]);
    }

    return randomString;
}

int main() {
    int length = 10; // specify the length of the random string
    std::string randomString = generateRandomString(length);
    std::cout << "Random String: " << randomString << std::endl;
    return 0;
}