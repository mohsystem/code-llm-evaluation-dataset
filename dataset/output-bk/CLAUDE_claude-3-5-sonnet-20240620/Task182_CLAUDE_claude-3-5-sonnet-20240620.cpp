
#include <iostream>
#include <string>
#include <regex>
#include <stdexcept>

std::string clean_phone_number(const std::string& phone) {
    // Remove all non-digit characters
    std::string cleaned = std::regex_replace(phone, std::regex("\\\\D"), "");
    
    // Remove country code if present
    if (cleaned.length() == 11 && cleaned[0] == \'1\') {
        cleaned = cleaned.substr(1);
    }
    
    // Check if the number is valid
    if (cleaned.length() != 10 || cleaned[0] < \'2\' || cleaned[0] > \'9\') {
        throw std::invalid_argument("Invalid phone number");
    }
    
    return cleaned;
}

int main() {
    std::vector<std::string> test_numbers = {
        "+1 (613)-995-0253",
        "613-995-0253",
        "1 613 995 0253",
        "613.995.0253"
    };

    for (const auto& number : test_numbers) {
        try {
            std::cout << clean_phone_number(number) << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
