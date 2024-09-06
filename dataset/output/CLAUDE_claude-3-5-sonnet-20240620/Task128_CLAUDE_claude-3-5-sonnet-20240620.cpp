
#include <iostream>
#include <random>
#include <string>

int generateRandomNumber(int minVal, int maxVal) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    return dis(gen);
}

std::string generateRandomToken(int length) {
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.length() - 1);
    
    std::string token;
    for (int i = 0; i < length; ++i) {
        token += characters[dis(gen)];
    }
    return token;
}

int main() {
    std::cout << "Random number: " << generateRandomNumber(1, 100) << std::endl;
    std::cout << "Random token: " << generateRandomToken(10) << std::endl;
    return 0;
}
