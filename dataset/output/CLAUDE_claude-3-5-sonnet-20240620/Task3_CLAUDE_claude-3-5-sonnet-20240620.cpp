
#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

bool isPangram(const std::string& sentence) {
    std::unordered_set<char> letters;
    for (char c : sentence) {
        if (std::isalpha(c)) {
            letters.insert(std::tolower(c));
        }
    }
    return letters.size() == 26;
}

int main() {
    std::string test1 = "The quick brown fox jumps over the lazy dog";
    std::string test2 = "This is not a pangram";
    std::cout << std::boolalpha << isPangram(test1) << std::endl;  // true
    std::cout << std::boolalpha << isPangram(test2) << std::endl;  // false
    return 0;
}
