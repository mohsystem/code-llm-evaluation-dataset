#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int wordScore(const string& word);

int main() {
    string sentence;
    getline(cin, sentence);
    
    istringstream iss(sentence);
    string highestWord;
    int highestScore = 0;

    string word;
    while (iss >> word) {
        int score = wordScore(word);
        if (score > highestScore) {
            highestScore = score;
            highestWord = word;
        }
    }

    cout << highestWord << endl;

    return 0;
}

int wordScore(const string& word) {
    int score = 0;
    for (char c : word) {
        score += tolower(c) - 'a' + 1;
    }
    return score;
}