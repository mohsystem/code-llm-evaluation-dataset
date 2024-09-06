#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generateRandomString(int length) {
    std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string str;
    srand(time(0));
    for (int i = 0; i < length; i++) {
        str += chars[rand() % chars.length()];
    }
    return str;
}

int main() {
    std::cout << generateRandomString(10) << std::endl;
    return 0;
}