#include <iostream>
#include <set>
#include <cctype>

bool isIsogram(const std::string& str) {
    std::set<char> set;
    for (char c : str) {
        char lower = std::tolower(c);
        if (!set.insert(lower).second) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha << isIsogram("Dermatoglyphics") << std::endl; // true
    std::cout << std::boolalpha << isIsogram("aba") << std::endl; // false
    std::cout << std::boolalpha << isIsogram("moOse") << std::endl; // false
    return 0;
}