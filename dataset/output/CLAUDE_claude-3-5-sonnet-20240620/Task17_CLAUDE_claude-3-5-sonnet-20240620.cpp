
#include <string>
#include <sstream>
#include <algorithm>

std::string toJadenCase(std::string phrase) {
    if (phrase.empty()) return phrase;
    
    std::istringstream iss(phrase);
    std::string word, result;
    
    while (iss >> word) {
        word[0] = std::toupper(word[0]);
        result += word + " ";
    }
    
    result.pop_back();  // Remove trailing space
    return result;
}
