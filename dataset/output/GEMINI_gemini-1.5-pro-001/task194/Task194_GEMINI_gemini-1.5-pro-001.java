/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    private int[][] H;
    
    public void findSecretWord(String[] words, Master master) {
        int n = words.length;
        this.H = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int matches = 0;
                for (int k = 0; k < 6; ++k) {
                    if (words[i].charAt(k) == words[j].charAt(k)) {
                        matches++;
                    }
                }
                this.H[i][j] = this.H[j][i] = matches;
            }
        }
        
        List<Integer> possible = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            possible.add(i);
        }
        
        int matches = 0;
        while (matches < 6) {
            int guess = findBestGuess(possible);
            matches = master.guess(words[guess]);
            if (matches == 6) {
                break;
            }
            List<Integer> newPossible = new ArrayList<>();
            for (int j : possible) {
                if (this.H[guess][j] == matches) {
                    newPossible.add(j);
                }
            }
            possible = newPossible;
        }
    }
    
    private int findBestGuess(List<Integer> possible) {
        int minMaxGroupSize = possible.size();
        int ans = -1;
        for (int i : possible) {
            int[] groups = new int[7];
            for (int j : possible) {
                if (i != j) {
                    groups[this.H[i][j]]++;
                }
            }
            int maxGroupSize = 0;
            for (int groupSize : groups) {
                maxGroupSize = Math.max(maxGroupSize, groupSize);
            }
            if (maxGroupSize < minMaxGroupSize) {
                minMaxGroupSize = maxGroupSize;
                ans = i;
            }
        }
        return ans;
    }
}