class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master* master) {
        for (int i = 0; i < 10; i++) {
            string guess = wordlist[rand() % wordlist.size()];
            int result = master->guess(guess);
            if (result == 6) return;
            vector<string> newList;
            for (string word : wordlist) {
                if (match(word, guess) == result) newList.push_back(word);
            }
            wordlist = newList;
        }
    }

    int match(string word1, string word2) {
        int count = 0;
        for (int i = 0; i < 6; i++) {
            if (word1[i] == word2[i]) count++;
        }
        return count;
    }
};