// C++
#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

bool isPangram(const std::string& sentence) {
    std::unordered_set<char> alphabetSet;
    for (char ch : sentence) {
        if (isalpha(ch)) {
            alphabetSet.insert(tolower(ch));
        }
    }
    return alphabetSet.size() == 26;
}

int main() {
    std::string sentence = "The quick brown fox jumps over the lazy dog";
    std::cout << (isPangram(sentence) ? "True" : "False") << std::endl;
    return 0;
}