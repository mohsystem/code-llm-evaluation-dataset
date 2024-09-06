
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

std::string clean_phone_number(const std::string& phone) {
    std::string digits;
    std::copy_if(phone.begin(), phone.end(), std::back_inserter(digits), ::isdigit);
    
    if (digits.length() == 11 && digits[0] == '1') {
        return digits.substr(1);
    } else if (digits.length() == 10) {
        return digits;
    } else {
        throw std::invalid_argument("Invalid phone number");
    }
}

int main() {
    try {
        std::cout << clean_phone_number("+1 (613)-995-0253") << std::endl;
        std::cout << clean_phone_number("613-995-0253") << std::endl;
        std::cout << clean_phone_number("1 613 995 0253") << std::endl;
        std::cout << clean_phone_number("613.995.0253") << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
