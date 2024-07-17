#include <iostream>
#include <string>
#include <vector>
#include <sstream>

bool validateIP(std::string ip) {
    std::vector<std::string> parts;
    std::stringstream ss(ip);
    std::string part;
    while (std::getline(ss, part, '.')) {
        parts.push_back(part);
    }
    if (parts.size() != 4) return false;
    for (const auto &part : parts) {
        int num = std::stoi(part);
        if (num < 0 || num > 255) return false;
    }
    return true;
}

int main() {
    std::string ip;
    std::cout << "Enter an IP address: ";
    std::std::getline(std::cin, ip);
    if (validateIP(ip)) {
        std::cout << "IP address is valid" << std::endl;
    } else {
        std::cout << "IP address is not valid" << std::endl;
    }
    return 0;
}