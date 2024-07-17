
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string url;
    std::cout << "Enter a URL: ";
    std::getline(std::cin, url);

    std::regex url_regex("^(https?://)?([\\\\w.-]+)\\\\.([a-z]{2,6})(:[0-9]+)?([/\\\\w .-]*)*/?$");

    if (std::regex_match(url, url_regex)) {
        std::cout << "Valid URL" << std::endl;
    } else {
        std::cout << "Invalid URL" << std::endl;
    }

    return 0;
}
