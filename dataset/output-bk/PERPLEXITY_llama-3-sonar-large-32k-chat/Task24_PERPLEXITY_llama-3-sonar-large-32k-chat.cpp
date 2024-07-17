#include <iostream>
#include <string>
#include <cctype>

bool validatePin(std::string pin) {
    if (pin.length() == 4 || pin.length() == 6) {
        for (char c : pin) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    std::cout << std::boolalpha << validatePin("1234") << std::endl; // true
    std::cout << std::boolalpha << validatePin("12345") << std::endl; // false
    std::cout << std::boolalpha << validatePin("a234") << std::endl; // false
    return 0;
}