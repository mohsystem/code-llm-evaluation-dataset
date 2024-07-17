
#include <iostream>
#include <random>
#include <string>

std::string generateSessionID() {
    const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int length = 32;
    
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, chars.size() - 1);
    
    std::string sessionID;
    for (int i = 0; i < length; ++i) {
        sessionID += chars[distribution(generator)];
    }
    
    return sessionID;
}

int main() {
    std::string sessionID = generateSessionID();
    std::cout << "Generated Session ID: " << sessionID << std::endl;
    return 0;
}
