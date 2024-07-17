
#include <string>
#include <sstream>
#include <algorithm>

std::string toJadenCase(std::string phrase) {
    if (phrase.empty()) {
        return "";
    }
    
    std::istringstream iss(phrase);
    std::ostringstream oss;
    std::string word;
    bool first = true;
    
    while (iss >> word) {
        if (!first) {
            oss << " ";
        }
        word[0] = std::toupper(word[0]);
        oss << word;
        first = false;
    }
    
    return oss.str();
}
