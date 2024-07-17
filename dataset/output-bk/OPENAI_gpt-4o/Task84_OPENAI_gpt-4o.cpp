#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string generateSessionIdCPP(int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string result;
    result.resize(length);
    for (int i = 0; i < length; i++) {
        int key = rand() % (sizeof(charset) - 1);
        result[i] = charset[key];
    }
    return result;
}

int main() {
    srand(time(0));
    std::cout << "C++ Session ID: " << generateSessionIdCPP(16) << std::endl;
    return 0;
}