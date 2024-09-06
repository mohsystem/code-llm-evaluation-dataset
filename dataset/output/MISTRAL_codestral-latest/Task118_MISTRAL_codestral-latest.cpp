#include <regex>
#include <iostream>

bool validate_ip(const std::string &ip) {
    const std::regex ipv4_pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    return std::regex_match(ip, ipv4_pattern);
}

int main() {
    std::cout << validate_ip("192.168.1.1") << std::endl;  // 1 (true)
    std::cout << validate_ip("256.168.1.1") << std::endl;  // 0 (false)
    return 0;
}