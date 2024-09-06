#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::string toJadenCase(std::string phrase) {
    std::istringstream iss(phrase);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word) {
        std::transform(word.begin(), word.begin() + 1, word.begin(), ::toupper);
        words.push_back(word);
    }

    std::ostringstream oss;
    std::copy(words.begin(), words.end() - 1, std::ostream_iterator<std::string>(oss, " "));
    oss << words.back();

    return oss.str();
}