class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master* master) {
        for (int i = 0; i < 10; i++) {
            string guess = wordlist[rand() % wordlist.size()];
            int res = master->guess(guess);
            if (res == 6) return;
            vector<string> newList;
            for (string w : wordlist) {
                int match = 0;
                for (int j = 0; j < 6; j++) {
                    if (w[j] == guess[j]) match++;
                }
                if (match == res) newList.push_back(w);
            }
            wordlist = newList;
        }
    }
};