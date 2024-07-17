#include <iostream>
#include <regex>

bool isValidURL(const std::string &url) {
    std::regex pattern("^(http|https|ftp)://[^\\s/$.?#].[^\\s]*$");
    return std::regex_match(url, pattern);
}

int main() {
    std::string urls[] = {
        "http://example.com",
        "https://example.com",
        "ftp://example.com",
        "invalidurl.com"
    };

    for (const auto &url : urls) {
        std::cout << url << " is " << (isValidURL(url) ? "valid" : "invalid") << std::endl;
    }

    return 0;
}
