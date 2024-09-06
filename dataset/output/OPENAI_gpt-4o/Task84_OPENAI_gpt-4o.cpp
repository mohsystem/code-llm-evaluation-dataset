#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generateSessionID() {
    std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string sessionID;
    for (int i = 0; i < 16; i++) {
        sessionID += characters[rand() % characters.length()];
    }
    return sessionID;
}

int main() {
    srand(time(0));
    std::cout << "CPP generated session ID: " << generateSessionID() << std::endl;
    return 0;
}