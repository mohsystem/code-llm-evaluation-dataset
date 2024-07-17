#include <iostream>
#include <regex>

bool isValidIP(const std::string& ip) {
    const std::regex pattern("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                             "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                             "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                             "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    return std::regex_match(ip, pattern);
}

int main() {
    std::string ip = "192.168.1.1";
    if (isValidIP(ip)) {
        std::cout << ip << " is a valid IP address.
";
    } else {
        std::cout << ip << " is not a valid IP address.
";
    }

    return 0;
}