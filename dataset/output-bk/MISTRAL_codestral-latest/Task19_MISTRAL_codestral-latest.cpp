#include <iostream>
#include <sstream>
#include <string>

std::string spinWords(const std::string& sentence) {
    std::istringstream iss(sentence);
    std::string word;
    std::string result;
    while (iss >> word) {
        if (word.length() >= 5) {
            std::reverse(word.begin(), word.end());
        }
        if (!result.empty()) {
            result += " ";
        }
        result += word;
    }
    return result;
}