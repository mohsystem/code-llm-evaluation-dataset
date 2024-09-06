
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string high(const string &s) {
    istringstream iss(s);
    vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};
    
    int maxScore = 0;
    string maxWord;
    
    for (const auto &word : words) {
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

int main() {
    cout << high("man i need a taxi up to ubud") << endl; // Output: taxi
    cout << high("what time are we climbing up the volcano") << endl; // Output: volcano
    cout << high("take me to semynak") << endl; // Output: semynak
    return 0;
}
