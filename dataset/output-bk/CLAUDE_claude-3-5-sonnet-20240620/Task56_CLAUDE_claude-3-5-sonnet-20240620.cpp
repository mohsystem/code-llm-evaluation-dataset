
#include <iostream>
#include <random>
#include <string>

std::string generate_token(size_t length) {
    const std::string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, charset.size() - 1);

    std::string token;
    for (size_t i = 0; i < length; ++i) {
        token += charset[distribution(generator)];
    }
    return token;
}

int main() {
    std::string token = generate_token(32);
    std::cout << "Generated token: " << token << std::endl;
    return 0;
}
