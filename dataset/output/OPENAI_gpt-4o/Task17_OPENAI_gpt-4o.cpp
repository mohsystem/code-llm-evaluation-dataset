#include <iostream>
#include <sstream>
#include <cctype>

std::string toJadenCase(const std::string &phrase) {
    if (phrase.empty()) {
        return "";
    }

    std::stringstream ss(phrase);
    std::stringstream jadenCase;
    std::string word;
    bool firstWord = true;

    while (ss >> word) {
        if (!firstWord) {
            jadenCase << " ";
        } else {
            firstWord = false;
        }
        word[0] = toupper(word[0]);
        jadenCase << word;
    }

    return jadenCase.str();
}

int main() {
    // Add test cases here
    std::cout << toJadenCase("How can mirrors be real if our eyes aren't real") << std::endl;
    std::cout << toJadenCase("") << std::endl;
    std::cout << toJadenCase("") << std::endl;
    return 0;
}