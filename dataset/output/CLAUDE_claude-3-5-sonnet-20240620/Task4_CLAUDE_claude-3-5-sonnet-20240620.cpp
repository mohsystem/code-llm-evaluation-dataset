
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

bool isIsogram(const std::string& str) {
    std::unordered_set<char> letters;
    std::string lowercaseStr = str;
    std::transform(lowercaseStr.begin(), lowercaseStr.end(), lowercaseStr.begin(), ::tolower);
    
    for (char c : lowercaseStr) {
        if (letters.find(c) != letters.end()) {
            return false;
        }
        letters.insert(c);
    }
    return true;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isIsogram("Dermatoglyphics") << std::endl;
    std::cout << isIsogram("aba") << std::endl;
    std::cout << isIsogram("moOse") << std::endl;
    return 0;
}
