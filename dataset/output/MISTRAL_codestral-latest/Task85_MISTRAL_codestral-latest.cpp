#include <iostream>
#include <cstdlib>
#include <ctime>

std::string generateRandomString(int length) {
    std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string result;

    srand(time(0));

    for (int i = 0; i < length; i++) {
        int index = rand() % letters.length();
        result += letters[index];
    }

    return result;
}

int main() {
    int length = 10; // specify the length of the string
    std::cout << generateRandomString(length) << std::endl;
    return 0;
}