
#include <iostream>
#include <string>
#include <regex>

bool isValidURL(const std::string& url) {
    const std::regex urlRegex(R"(^(https?|ftp)://[^\\s/$.?#].[^\\s]*$)", std::regex::icase);
    return std::regex_match(url, urlRegex);
}

int main() {
    std::string url;
    while (true) {
        std::cout << "Enter a URL (or 'quit' to exit): ";
        std::getline(std::cin, url);
        if (url == "quit") {
            break;
        }
        if (isValidURL(url)) {
            std::cout << "Valid URL" << std::endl;
        } else {
            std::cout << "Invalid URL" << std::endl;
        }
    }
    return 0;
}
