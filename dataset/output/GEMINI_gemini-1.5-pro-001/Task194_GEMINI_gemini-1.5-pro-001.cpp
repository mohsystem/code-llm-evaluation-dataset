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
    vector<vector<int>> H;
    
    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();
        H.resize(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int matches = 0;
                for (int k = 0; k < 6; ++k) {
                    if (words[i][k] == words[j][k]) {
                        matches++;
                    }
                }
                H[i][j] = H[j][i] = matches;
            }
        }
        
        vector<int> possible(n);
        iota(possible.begin(), possible.end(), 0);
        
        int matches = 0;
        while (matches < 6) {
            int guess = findBestGuess(possible, words);
            matches = master.guess(words[guess]);
            if (matches == 6) {
                break;
            }
            vector<int> newPossible;
            for (int j : possible) {
                if (H[guess][j] == matches) {
                    newPossible.push_back(j);
                }
            }
            possible = newPossible;
        }
    }
    
private:
    int findBestGuess(const vector<int>& possible, const vector<string>& words) {
        int minMaxGroupSize = possible.size();
        int ans = -1;
        for (int i : possible) {
            vector<int> groups(7, 0);
            for (int j : possible) {
                if (i != j) {
                    groups[H[i][j]]++;
                }
            }
            int maxGroupSize = *max_element(groups.begin(), groups.end());
            if (maxGroupSize < minMaxGroupSize) {
                minMaxGroupSize = maxGroupSize;
                ans = i;
            }
        }
        return ans;
    }
};