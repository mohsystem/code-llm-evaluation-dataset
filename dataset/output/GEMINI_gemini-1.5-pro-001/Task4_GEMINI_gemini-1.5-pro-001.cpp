#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

bool is_isogram(const std::string& str) {
    if (str.empty()) {
        return true;
    }

    std::string lower_str = str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
                   
    std::unordered_set<char> seen;
    for (char c : lower_str) {
        if (seen.count(c) > 0) {
            return false;
        }
        seen.insert(c);
    }

    return true;
}

int main() {
    std::cout << (is_isogram("Dermatoglyphics") ? "true" : "false") << std::endl;
    std::cout << (is_isogram("aba") ? "true" : "false") << std::endl;
    std::cout << (is_isogram("moOse") ? "true" : "false") << std::endl;
    return 0;
}