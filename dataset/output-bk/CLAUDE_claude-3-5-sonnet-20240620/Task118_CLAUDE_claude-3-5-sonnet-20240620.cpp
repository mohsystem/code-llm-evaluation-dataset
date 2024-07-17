
#include <iostream>
#include <string>
#include <regex>
#include <sstream>

bool is_valid_ipv4(const std::string& ip) {
    std::istringstream iss(ip);
    std::string octet;
    int count = 0;
    while (std::getline(iss, octet, \'.\')) {
        count++;
        if (count > 4 || octet.empty() || octet.size() > 3) {
            return false;
        }
        if (octet[0] == \'0\' && octet.size() > 1) {
            return false;
        }
        for (char c : octet) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        int num = std::stoi(octet);
        if (num < 0 || num > 255) {
            return false;
        }
    }
    return count == 4;
}

bool is_valid_ipv6(const std::string& ip) {
    std::regex ipv6_regex("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$");
    return std::regex_match(ip, ipv6_regex);
}

int main() {
    std::string ip;
    std::cout << "Enter an IP address: ";
    std::getline(std::cin, ip);

    if (is_valid_ipv4(ip)) {
        std::cout << "Valid IPv4 address" << std::endl;
    } else if (is_valid_ipv6(ip)) {
        std::cout << "Valid IPv6 address" << std::endl;
    } else {
        std::cout << "Invalid IP address" << std::endl;
    }

    return 0;
}
