#include <string>
#include <vector>

using namespace std;

string highestScoringWord(const string& str) {
    vector<string> words;
    string currentWord;
    for (char c : str) {
        if (c == ' ') {
            words.push_back(currentWord);
            currentWord = "";
        } else {
            currentWord += c;
        }
    }
    words.push_back(currentWord);

    string highestWord;
    int highestScore = 0;
    for (const string& word : words) {
        int score = 0;
        for (char c : word) {
            score += tolower(c) - 'a' + 1;
        }
        if (score > highestScore) {
            highestScore = score;
            highestWord = word;
        }
    }

    return highestWord;
}