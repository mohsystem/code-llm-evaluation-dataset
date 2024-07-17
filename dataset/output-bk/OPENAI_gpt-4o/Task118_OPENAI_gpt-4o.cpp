#include <iostream>
#include <regex>

bool isValidIPAddress(std::string ip) {
    std::regex ipPattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    return std::regex_match(ip, ipPattern);
}

int main() {
    std::cout << isValidIPAddress("192.168.0.1") << std::endl; // true - 1
    std::cout << isValidIPAddress("256.256.256.256") << std::endl; // false - 0
    return 0;
}