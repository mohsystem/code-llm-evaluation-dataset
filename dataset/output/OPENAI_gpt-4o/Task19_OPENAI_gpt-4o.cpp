#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string spinWords(const std::string &sentence) {
    std::istringstream iss(sentence);
    std::ostringstream oss;
    std::string word;
    bool first = true;

    while (iss >> word) {
        if (!first) oss << " ";
        if (word.length() >= 5) {
            std::reverse(word.begin(), word.end());
        }
        oss << word;
        first = false;
    }
    return oss.str();
}

int main() {
    std::vector<std::string> examples = {"Hey fellow warriors", "This is a test", "This is another test"};
    for (const auto& example : examples) {
        std::cout << spinWords(example) << std::endl;
    }
    return 0;
}