#include <iostream>
#include <vector>
#include <regex>

bool validateIP(const std::string &ip) {
    const std::regex pattern("^([0-9]{1,3}\\.){3}[0-9]{1,3}$");
    if (!std::regex_match(ip, pattern)) {
        return false;
    }
    std::stringstream ss(ip);
    std::string part;
    while (std::getline(ss, part, '.')) {
        int num = std::stoi(part);
        if (num < 0 || num > 255) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::string> ips = {"192.168.1.1", "256.256.256.256", "123.045.067.089"};
    std::cout << "Validated IPs: ";
    for (const auto &ip : ips) {
        if (validateIP(ip)) {
            std::cout << ip << " ";
        }
    }
    return 0;
}