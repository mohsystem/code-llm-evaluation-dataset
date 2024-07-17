#include <regex>
#include <string>

std::string cleanPhoneNumber(const std::string& phoneNumber) {
    std::string cleanedNumber = std::regex_replace(phoneNumber, std::regex("\\D"), "");
    if (cleanedNumber.substr(0, 1) == "1") {
        cleanedNumber = cleanedNumber.substr(1);
    }
    return cleanedNumber;
}