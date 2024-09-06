#include <iostream>
#include <regex>
#include <string>

bool validateUrl(const std::string& url) {
    std::regex pattern("^(https?|ftp|file)://[-A-Za-z0-9+&@#/%?=~_|!:,.;]*[-A-Za-z0-9+&@#/%=~_|]");
    return std::regex_match(url, pattern);
}

int main() {
    std::string url;
    std::cout << "Enter a URL: ";
    std::getline(std::cin, url);
    if (validateUrl(url)) {
        std::cout << "URL is valid" << std::endl;
    } else {
        std::cout << "URL is not valid" << std::endl;
    }
    return 0;
}