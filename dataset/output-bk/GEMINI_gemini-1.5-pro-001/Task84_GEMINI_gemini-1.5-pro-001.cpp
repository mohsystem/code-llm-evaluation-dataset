#include <iostream>
#include <random>
#include <string>

std::string generateSessionId(size_t length) {
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, charset.size() - 1);
    std::string sessionId;
    sessionId.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        sessionId += charset[distribution(generator)];
    }
    return sessionId;
}

int main() {
    std::cout << generateSessionId(32) << std::endl;
    return 0;
}