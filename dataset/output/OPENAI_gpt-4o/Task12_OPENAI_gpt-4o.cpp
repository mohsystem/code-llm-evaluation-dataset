#include <iostream>
#include <sstream>
#include <string>

std::string high(const std::string& inputString) {
    std::istringstream iss(inputString);
    std::string word, bestWord;
    int maxScore = 0;

    while (iss >> word) {
        int score = 0;
        for (char c : word) {
            score += c - 'a' + 1;
        }

        if (score > maxScore) {
            maxScore = score;
            bestWord = word;
        }
    }

    return bestWord;
}

int main() {
    std::string inputString = "abad test example";
    std::cout << high(inputString) << std::endl;
    return 0;
}