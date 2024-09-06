// C++ code
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int matches(string a, string b) {
            int count = 0;
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == b[i]) {
                    count++;
                }
            }
            return count;
        }

        void findSecretWord(vector<string>& possibleWords) {
            if (possibleWords.empty()) {
                return;
            }
            if (possibleWords.size() == 1) {
                master.guess(possibleWords[0]);
                return;
            }

            // Choose a word with the least number of matches with other words
            vector<int> wordCount(possibleWords.size(), 0);
            for (int i = 0; i < possibleWords.size(); i++) {
                for (int j = i + 1; j < possibleWords.size(); j++) {
                    int matchesCount = matches(possibleWords[i], possibleWords[j]);
                    wordCount[i] += matchesCount;
                    wordCount[j] += matchesCount;
                }
            }
            int minCount = *min_element(wordCount.begin(), wordCount.end());
            string guess = possibleWords[distance(wordCount.begin(), find(wordCount.begin(), wordCount.end(), minCount))];

            int matchesCount = master.guess(guess);
            if (matchesCount == 6) {
                return;
            }

            // Filter out words that don't match the number of matches with the guess
            vector<string> newPossibleWords;
            for (string word : possibleWords) {
                if (matches(word, guess) == matchesCount) {
                    newPossibleWords.push_back(word);
                }
            }
            findSecretWord(newPossibleWords);
        }

        findSecretWord(words);
    }
};