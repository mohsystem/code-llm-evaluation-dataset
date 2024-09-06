
import java.util.*;

class Master {
    private String secret;
    private int guesses;

    public Master(String secret) {
        this.secret = secret;
        this.guesses = 0;
    }

    public int guess(String word) {
        guesses++;
        int matches = 0;
        for (int i = 0; i < 6; i++) {
            if (secret.charAt(i) == word.charAt(i)) {
                matches++;
            }
        }
        return matches;
    }

    public int getGuesses() {
        return guesses;
    }
}

class Solution {
    public void findSecretWord(String[] words, Master master) {
        List<String> wordList = new ArrayList<>(Arrays.asList(words));
        Random random = new Random();

        for (int i = 0; i < 10; i++) {
            String guess = wordList.get(random.nextInt(wordList.size()));
            int matches = master.guess(guess);
            if (matches == 6) return;

            List<String> newList = new ArrayList<>();
            for (String word : wordList) {
                if (getMatches(word, guess) == matches) {
                    newList.add(word);
                }
            }
            wordList = newList;
        }
    }

    private int getMatches(String word1, String word2) {
        int matches = 0;
        for (int i = 0; i < 6; i++) {
            if (word1.charAt(i) == word2.charAt(i)) {
                matches++;
            }
        }
        return matches;
    }

    public static void main(String[] args) {
        String secret = "acckzz";
        String[] words = {"acckzz", "ccbazz", "eiowzz", "abcczz"};
        Master master = new Master(secret);
        Solution solution = new Solution();
        solution.findSecretWord(words, master);
        System.out.println(master.getGuesses() <= 10 ? "You guessed the secret word correctly." : "Either you took too many guesses, or you did not find the secret word.");
    }
}
