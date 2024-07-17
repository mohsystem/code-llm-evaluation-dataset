#include <iostream>
#include <random>

std::string generateRandomString(int length) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<char> distribution('a', 'z');

    std::string randomString;
    for (int i = 0; i < length; ++i) {
        randomString += (char)distribution(generator);
    }

    return randomString;
}

int main() {
    int length = 10; // Specify the desired length of the random string
    std::string randomString = generateRandomString(length);
    std::cout << randomString << std::endl;

    return 0;
}