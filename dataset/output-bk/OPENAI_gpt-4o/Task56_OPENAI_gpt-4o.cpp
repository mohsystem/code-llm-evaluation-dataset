#include <iostream>
#include <random>
#include <string>

std::string generateToken(size_t length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);

    std::string token;
    for (size_t i = 0; i < length; ++i) {
        token += charset[dist(rng)];
    }
    return token;
}

int main() {
    std::cout << "C++ Token: " << generateToken(36) << std::endl;
    return 0;
}