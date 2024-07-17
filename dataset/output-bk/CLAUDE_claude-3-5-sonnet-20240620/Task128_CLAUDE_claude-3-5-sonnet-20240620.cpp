
#include <iostream>
#include <random>
#include <string>

int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    return dis(gen);
}

std::string generateRandomToken() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 61);
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string token;
    for (int i = 0; i < 8; ++i) {
        token += characters[dis(gen)];
    }
    return token;
}

int main() {
    std::cout << "Random Number: " << generateRandomNumber() << std::endl;
    std::cout << "Random Token: " << generateRandomToken() << std::endl;
    return 0;
}
