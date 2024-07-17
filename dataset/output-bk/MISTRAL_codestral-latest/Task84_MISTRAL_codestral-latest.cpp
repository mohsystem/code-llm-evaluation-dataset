#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

std::string generateSessionId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);
    std::stringstream ss;
    int i;
    for (i = 0; i < 8; i++) {
        ss << std::hex << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 4; i++) {
        ss << std::hex << dis(gen);
    }
    ss << "-4";
    for (i = 0; i < 3; i++) {
        ss << std::hex << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 4; i++) {
        ss << std::hex << dis(gen);
    }
    ss << "-";
    for (i = 0; i < 12; i++) {
        ss << std::hex << dis(gen);
    }
    return ss.str();
}

int main() {
    std::cout << generateSessionId() << std::endl;
    return 0;
}