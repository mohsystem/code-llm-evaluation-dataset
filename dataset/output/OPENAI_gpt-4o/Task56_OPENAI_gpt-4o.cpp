#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>
#include <unistd.h>

void generateToken() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    char token[16];
    for (int i = 0; i < 16; ++i) {
        token[i] = static_cast<char>(dis(gen));
    }

    std::cout << "C++ Generated Token: ";
    for (char c : token) {
        printf("%02x", (unsigned char)c);
    }
    std::cout << std::endl;
}

int main() {
    sleep(5); // Waiting for 5 seconds
    generateToken();
    return 0;
}