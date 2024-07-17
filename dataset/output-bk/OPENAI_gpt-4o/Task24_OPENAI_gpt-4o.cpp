// C++ code
#include <iostream>
#include <string>
#include <cctype>

bool validatePin(const std::string& pin) {
    int len = pin.length();
    if (len != 4 && len != 6) return false;
    for (char c : pin) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    std::cout << validatePin("1234") << std::endl;   // 1 (true)
    std::cout << validatePin("12345") << std::endl;  // 0 (false)
    std::cout << validatePin("a234") << std::endl;   // 0 (false)
    return 0;
}