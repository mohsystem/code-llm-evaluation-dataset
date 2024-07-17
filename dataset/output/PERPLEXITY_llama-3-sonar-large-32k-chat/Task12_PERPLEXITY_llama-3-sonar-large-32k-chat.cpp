#include <iostream>
#include <string>
#include <sstream>

std::string high(const std::string &s) {
    std::istringstream iss(s);
    std::string word, maxWord;
    int maxScore = 0;
    while (iss >> word) {
        int score = 0;
        for (char c : word) {
            score += c - 'a' + 1;
        }
        if (score > maxScore) {
            maxScore = score;
            maxWord = word;
        }
    }
    return maxWord;
}