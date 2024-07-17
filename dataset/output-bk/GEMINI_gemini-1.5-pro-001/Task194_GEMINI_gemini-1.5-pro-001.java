/**
 * // This is Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    public void findSecretWord(String[] words, Master master) {
        int n = words.length;
        int[][] H = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                H[i][j] = H[j][i] = match(words[i], words[j]);
            }
        }

        List<Integer> possible = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            possible.add(i);
        }
        int matches = 0;
        while (!possible.isEmpty() && master.guess(words[possible.get(0)]) != 6) {
            int guess = rand.nextInt(possible.size());
            matches = master.guess(words[possible.get(guess)]);
            List<Integer> nextPossible = new ArrayList<>();
            for (int j : possible) {
                if (H[possible.get(guess)][j] == matches) {
                    nextPossible.add(j);
                }
            }
            possible = nextPossible;
        }
    }

    private int match(String a, String b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a.charAt(i) == b.charAt(i)) {
                ++matches;
            }
        }
        return matches;
    }
    private Random rand = new Random();
}