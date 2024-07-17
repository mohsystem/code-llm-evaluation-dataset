#include <iostream>
#include <unordered_set>
#include <cctype>

bool isIsogram(const std::string& str) {
    std::unordered_set<char> set;
    for (char c : str) {
        if (set.find(tolower(c)) != set.end()) {
            return false;
        }
        set.insert(tolower(c));
    }
    return true;
}

int main() {
    std::cout << isIsogram("Dermatoglyphics") << std::endl; // 1 (true)
    std::cout << isIsogram("aba") << std::endl; // 0 (false)
    std::cout << isIsogram("moOse") << std::endl; // 0 (false)
    return 0;
}