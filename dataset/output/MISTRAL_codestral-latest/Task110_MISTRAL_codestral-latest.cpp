#include <iostream>
#include <regex>

bool validateURL(const std::string& url) {
    const std::regex pattern("^(https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]");
    return std::regex_match(url, pattern);
}

int main() {
    std::string url;
    std::cout << "Enter a URL: ";
    std::getline(std::cin, url);
    if (validateURL(url)) {
        std::cout << "Valid URL\n";
    } else {
        std::cout << "Invalid URL\n";
    }
    return 0;
}