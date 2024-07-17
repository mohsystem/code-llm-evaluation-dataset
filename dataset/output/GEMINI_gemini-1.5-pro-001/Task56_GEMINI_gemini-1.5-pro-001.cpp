#include <iostream>
#include <random>
#include <string>

std::string generate_token(int length = 32) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string token;
    for (int i = 0; i < length; ++i) {
        token += characters[distribution(generator)];
    }
    return token;
}

int main() {
    std::string token = generate_token();
    std::cout << token << std::endl;
    return 0;
}