
#include <iostream>
#include <regex>
#include <string>
#include <sstream>

bool validateIP(const std::string& ip) {
    std::regex pattern("^(\\\\d{1,3}\\\\.){3}\\\\d{1,3}$");
    if (!std::regex_match(ip, pattern)) {
        return false;
    }
    std::istringstream iss(ip);
    std::string octet;
    while (std::getline(iss, octet, '.')) {
        int value = std::stoi(octet);
        if (value < 0 || value > 255) {
            return false;
        }
    }
    return true;
}

void processIP(const std::string& ip) {
    if (validateIP(ip)) {
        std::istringstream iss(ip);
        std::string octet;
        std::getline(iss, octet, '.');
        int firstOctet = std::stoi(octet);
        std::string classType;
        if (firstOctet >= 1 && firstOctet <= 126) {
            classType = "A";
        } else if (firstOctet >= 128 && firstOctet <= 191) {
            classType = "B";
        } else if (firstOctet >= 192 && firstOctet <= 223) {
            classType = "C";
        } else if (firstOctet >= 224 && firstOctet <= 239) {
            classType = "D";
        } else if (firstOctet >= 240 && firstOctet <= 255) {
            classType = "E";
        }
        std::cout << "Valid IP address. Class: " << classType << std::endl;
    } else {
        std::cout << "Invalid IP address" << std::endl;
    }
}

int main() {
    std::string ip;
    std::cout << "Enter an IP address: ";
    std::getline(std::cin, ip);
    processIP(ip);
    return 0;
}
