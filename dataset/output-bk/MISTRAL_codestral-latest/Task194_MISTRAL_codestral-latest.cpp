// C++
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        for (int i = 0; i < 10; i++) {
            int guessIndex = rand() % words.size();
            string guess = words[guessIndex];
            int matches = master.guess(guess);
            if (matches == 6) {
                cout << "You guessed the secret word correctly." << endl;
                return;
            }
            vector<string> newWords;
            for (string word : words) {
                if (match(word, guess, matches)) {
                    newWords.push_back(word);
                }
            }
            words = newWords;
        }
        cout << "Either you took too many guesses, or you did not find the secret word." << endl;
    }

private:
    bool match(string word, string guess, int matches) {
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess[i]) {
                count++;
            }
        }
        return count == matches;
    }
};