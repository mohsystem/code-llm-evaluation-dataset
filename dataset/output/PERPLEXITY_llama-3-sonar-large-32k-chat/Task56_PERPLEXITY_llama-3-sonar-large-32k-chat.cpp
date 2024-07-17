#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main() {
    std::string token;
    srand(static_cast<unsigned int>(time(0)));
    for(int i = 0; i < 32; i++) {
        token += "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"[rand() % 62];
    }
    std::cout << "Token: " << token << std::endl;
    return 0;
}