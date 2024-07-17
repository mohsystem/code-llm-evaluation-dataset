/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();
        vector<vector<int>> H(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                H[i][j] = H[j][i] = match(words[i], words[j]);
            }
        }
        
        vector<int> possible(n);
        iota(possible.begin(), possible.end(), 0);
        int matches = 0;
        while (!possible.empty() && master.guess(words[possible[0]]) != 6) {
            int guess = rand() % possible.size();
            matches = master.guess(words[possible[guess]]);
            vector<int> nextPossible;
            for (int j : possible) {
                if (H[possible[guess]][j] == matches) {
                    nextPossible.push_back(j);
                }
            }
            possible = nextPossible;
        }
    }

private:
    int match(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == b[i]) {
                ++matches;
            }
        }
        return matches;
    }
};