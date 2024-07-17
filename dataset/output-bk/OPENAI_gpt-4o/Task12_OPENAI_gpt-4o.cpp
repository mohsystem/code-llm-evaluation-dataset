#include <iostream>
#include <sstream>
#include <string>

int wordScore(const std::string& word) {
    int score = 0;
    for (char ch : word) {
        score += ch - 'a' + 1;
    }
    return score;
}

std::string highestScoringWord(const std::string& str) {
    std::istringstream stream(str);
    std::string word, bestWord;
    int highestScore = 0;

    while (stream >> word) {
        int score = wordScore(word);
        if (score > highestScore) {
            highestScore = score;
            bestWord = word;
        }
    }

    return bestWord;
}

int main() {
    std::string input = "example input sentence";
    std::cout << highestScoringWord(input) << std::endl;
    return 0;
}