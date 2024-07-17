#include <iostream>
#include <regex>
#include <string>

std::string cleanPhoneNumber(const std::string &phone) {
    std::string cleaned_phone = std::regex_replace(phone, std::regex("\\D"), "");
    if (cleaned_phone.length() == 11 && cleaned_phone[0] == '1') {
        cleaned_phone = cleaned_phone.substr(1);
    }
    return cleaned_phone;
}

int main() {
    std::string numbers[] = {
        "+1 (613)-995-0253",
        "613-995-0253",
        "1 613 995 0253",
        "613.995.0253"
    };

    for (const auto &number : numbers) {
        std::cout << cleanPhoneNumber(number) << std::endl;
    }

    return 0;
}