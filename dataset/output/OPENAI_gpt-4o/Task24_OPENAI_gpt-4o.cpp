#include <iostream>
#include <string>
#include <cctype>

bool validatePin(const std::string& pin) {
    if (pin.length() == 4 || pin.length() == 6) {
        for (char c : pin) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << validatePin("1234") << std::endl;  // true
    std::cout << validatePin("12345") << std::endl; // false
    std::cout << validatePin("a234") << std::endl;  // false
    return 0;
}