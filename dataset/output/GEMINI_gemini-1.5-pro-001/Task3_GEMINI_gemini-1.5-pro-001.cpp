#include <iostream>
#include <string>
#include <set>
#include <algorithm>

bool isPangram(const std::string& text) {
    if (text.length() < 26) {
        return false;
    }

    std::set<char> letters;
    for (char c : text) {
        if (std::isalpha(c)) {
            letters.insert(std::tolower(c));
        }
    }
    return letters.size() == 26;
}

int main() {
    std::string text = "The quick brown fox jumps over the lazy dog";
    std::cout << (isPangram(text) ? "True" : "False") << std::endl;
    return 0;
}