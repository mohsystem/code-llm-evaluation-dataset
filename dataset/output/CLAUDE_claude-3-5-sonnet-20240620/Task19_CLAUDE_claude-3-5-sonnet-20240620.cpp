
#include <string>
#include <sstream>
#include <algorithm>

std::string spinWords(const std::string &sentence) {
    std::istringstream iss(sentence);
    std::string word, result;
    while (iss >> word) {
        if (word.length() >= 5) {
            std::reverse(word.begin(), word.end());
        }
        result += word + " ";
    }
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}
