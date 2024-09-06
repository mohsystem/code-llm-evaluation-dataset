#include <iostream>
#include <regex>

bool validateURL(const std::string &url) {
    const std::regex pattern("(http|https|ftp)://([^\\s/$.?#].[^\\s]*)");
    return std::regex_match(url, pattern);
}

int main() {
    std::string userURL;
    std::cout << "Enter URL: ";
    std::cin >> userURL;

    if (validateURL(userURL)) {
        std::cout << "Valid URL\n";
    } else {
        std::cout << "Invalid URL\n";
    }

    return 0;
}