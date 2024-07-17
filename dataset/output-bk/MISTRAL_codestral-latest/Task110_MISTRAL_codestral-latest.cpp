#include <iostream>
#include <regex>

bool isValidURL(const std::string &url) {
    const std::regex urlPattern("^(https?|ftp|file)://[-a-zA-Z0-9+&@#/%?=~_|!:,.;]*[-a-zA-Z0-9+&@#/%=~_|]");
    return std::regex_match(url, urlPattern);
}

int main() {
    std::string url = "http://www.example.com";
    if (isValidURL(url)) {
        std::cout << "URL is valid" << std::endl;
    } else {
        std::cout << "URL is not valid" << std::endl;
    }
    return 0;
}