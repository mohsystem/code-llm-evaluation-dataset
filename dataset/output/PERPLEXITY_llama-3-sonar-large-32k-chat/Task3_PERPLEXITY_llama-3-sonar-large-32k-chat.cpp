#include <iostream>
#include <string>
#include <cctype>

bool isPangram(const std::string& s) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (char c : alphabet) {
        bool found = false;
        for (char sc : s) {
            if (std::tolower(sc) == c) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha << isPangram("The quick brown fox jumps over the lazy dog") << std::endl;  // true
    std::cout << std::boolalpha << isPangram("Hello World") << std::endl;  // false
    return 0;
}