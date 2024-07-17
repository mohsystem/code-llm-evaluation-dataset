#include <iostream>
#include <regex>
#include <string>

int main() {
    std::regex url_regex("^((https?|ftp|file)://)?(-\\w+\\.){1,}(com|org|net|gov|mil|biz|info|mobi|name|aero|jobs|edu|co\\.uk|ac\\.uk|gov\\.uk|mil\\.uk|nhs\\.uk|police\\.uk|mod\\.uk|travel|local|me\\.uk|ltd\\.uk|plc\\.uk|net\\.uk|sch\\.uk)(:\\d+)?(/([\\w\\-\\.\\?\\,\\\\\\+&%*#=]*)?)?$");
    std::string url;
    std::cout << "Enter a URL: ";
    std::getline(std::cin, url);
    if (std::regex_match(url, url_regex)) {
        std::cout << "URL is valid" << std::endl;
    } else {
        std::cout << "URL is not valid" << std::endl;
    }
    return 0;
}