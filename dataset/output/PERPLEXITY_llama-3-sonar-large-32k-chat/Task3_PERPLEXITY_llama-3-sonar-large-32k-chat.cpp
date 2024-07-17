#include <cctype>
#include <iostream>
#include <string>

bool check(const std::string &sentence) {
    bool alphabet[26] = {false};
    for (char c : sentence) {
        c = tolower(c);
        if (c >= 'a' && c <= 'z') {
            alphabet[c - 'a'] = true;
        }
    }
    for (bool b : alphabet) {
        if (!b) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha << check("The quick brown fox jumps over the lazy dog") << std::endl; // true
    std::cout << std::boolalpha << check("Hello World") << std::endl; // false
    return 0;
}