#include <iostream>
#include <cstdlib>
#include <ctime>

const std::string CHARACTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int TOKEN_LENGTH = 10;

std::string generateRandomToken() {
    std::string token;
    srand(time(0));

    for (int i = 0; i < TOKEN_LENGTH; i++) {
        int randomIndex = rand() % CHARACTERS.length();
        token += CHARACTERS[randomIndex];
    }

    return token;
}

int main() {
    std::cout << generateRandomToken() << std::endl;
    return 0;
}