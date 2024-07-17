
#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string email, phone;
    
    std::cout << "Enter an email address: ";
    std::getline(std::cin, email);
    
    std::regex email_regex("^[A-Za-z0-9+_.-]+@[A-Za-z0-9.-]+$");
    
    if (std::regex_match(email, email_regex)) {
        std::cout << "Valid email address" << std::endl;
    } else {
        std::cout << "Invalid email address" << std::endl;
    }
    
    std::cout << "Enter a phone number (XXX-XXX-XXXX): ";
    std::getline(std::cin, phone);
    
    std::regex phone_regex("^\\\\d{3}-\\\\d{3}-\\\\d{4}$");
    
    if (std::regex_match(phone, phone_regex)) {
        std::cout << "Valid phone number" << std::endl;
    } else {
        std::cout << "Invalid phone number" << std::endl;
    }
    
    return 0;
}
