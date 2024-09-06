#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

std::string toJadenCase(std::string phrase) {
    if (phrase.empty()) return "";
    std::istringstream iss(phrase);
    std::string word;
    std::string result;
    while (iss >> word) {
        word[0] = std::toupper(word[0]);
        result += word + " ";
    }
    return result.substr(0, result.size() - 1);
}