
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

class Master {
private:
    string secret;
    int guesses;

public:
    Master(string s) : secret(s), guesses(0) {}

    int guess(string word) {
        guesses++;
        int matches = 0;
        for (int i = 0; i < 6; i++) {
            if (secret[i] == word[i]) {
                matches++;
            }
        }
        return matches;
    }

    int getGuesses() {
        return guesses;
    }
};

class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        random_device rd;
        mt19937 gen(rd());

        for (int i = 0; i < 10; i++) {
            uniform_int_distribution<> dis(0, words.size() - 1);
            string guess = words[dis(gen)];
            int matches = master.guess(guess);
            if (matches == 6) return;

            vector<string> newWords;
            for (const string& word : words) {
                if (getMatches(word, guess) == matches) {
                    newWords.push_back(word);
                }
            }
            words = newWords;
        }
    }

private:
    int getMatches(const string& word1, const string& word2) {
        int matches = 0;
        for (int i = 0; i < 6; i++) {
            if (word1[i] == word2[i]) {
                matches++;
            }
        }
        return matches;
    }
};

int main() {
    string secret = "acckzz";
    vector<string> words = {"acckzz", "ccbazz", "eiowzz", "abcczz"};
    Master master(secret);
    Solution solution;
    solution.findSecretWord(words, master);
    cout << (master.getGuesses() <= 10 ? "You guessed the secret word correctly." : "Either you took too many guesses, or you did not find the secret word.") << endl;
    return 0;
}
