#include <iostream>
#include <regex>
#include <string>

std::string cleanPhoneNumber(std::string phoneNumber) {
    std::regex re("[^\\d]");
    phoneNumber = std::regex_replace(phoneNumber, re, "");
    if (phoneNumber.size() > 0 && phoneNumber[0] == '1') {
        phoneNumber.erase(0, 1);
    }
    return phoneNumber;
}

int main() {
    std::string phoneNumber;
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << cleanPhoneNumber(phoneNumber) << std::endl;
    return 0;
}