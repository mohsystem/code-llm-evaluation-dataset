#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

std::string high_scoring_word(std::string input_string) {
    std::istringstream iss(input_string);
    std::vector<std::string> words;
    std::vector<int> scores;
    std::string word;

    while (iss >> word) {
        words.push_back(word);
        int score = 0;
        for (char c : word) {
            score += c - 'a' + 1;
        }
        scores.push_back(score);
    }

    auto max_score = std::max_element(scores.begin(), scores.end());
    return words[std::distance(scores.begin(), max_score)];
}