
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool is_isogram(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::sort(str.begin(), str.end());
    return std::unique(str.begin(), str.end()) == str.end();
}

int main() {
    std::cout << std::boolalpha;
    std::cout << is_isogram("Dermatoglyphics") << std::endl;  // true
    std::cout << is_isogram("aba") << std::endl;  // false
    std::cout << is_isogram("moOse") << std::endl;  // false
    return 0;
}
