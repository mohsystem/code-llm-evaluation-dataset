
#include <iostream>
#include <random>
#include <string>

std::string generate_token(int length = 32) {
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, charset.length() - 1);

    std::string token;
    for (int i = 0; i < length; ++i) {
        token += charset[distribution(generator)];
    }
    return token;
}

int main() {
    std::string auth_token = generate_token();
    std::cout << "Generated authentication token: " << auth_token << std::endl;
    return 0;
}
