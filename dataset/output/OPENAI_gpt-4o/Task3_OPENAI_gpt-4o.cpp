#include <iostream>
#include <set>
#include <cctype>

bool isPangram(const std::string& s) {
    std::set<char> alphabetSet;
    for (char c : s) {
        if (std::isalpha(c)) {
            alphabetSet.insert(std::tolower(c));
        }
    }
    return alphabetSet.size() == 26;
}

int main() {
    std::string s = "The quick brown fox jumps over the lazy dog";
    std::cout << (isPangram(s) ? "true" : "false") << std::endl;  // Output: true
    return 0;
}