
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        for (int i = 0, n = 0; i < 10 && n < 6; ++i) {
            string guess = words[rand() % words.size()];
            n = master.guess(guess);
            vector<string> candidates;
            for (string w : words)
                if (match(guess, w) == n)
                    candidates.push_back(w);
            words = candidates;
        }
    }
private:
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] == b[i])
                matches++;
        return matches;
    }
};
