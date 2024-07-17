
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int calculateScore(const string& word) {
    int score = 0;
    for (char c : word) {
        score += tolower(c) - \'a\' + 1;
    }
    return score;
}

int main() {
    string input;
    getline(cin, input);

    istringstream iss(input);
    vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};

    string highestScoringWord = "";
    int highestScore = 0;

    for (const string& word : words) {
        int score = calculateScore(word);
        if (score > highestScore) {
            highestScore = score;
            highestScoringWord = word;
        }
    }

    cout << highestScoringWord << endl;

    return 0;
}
