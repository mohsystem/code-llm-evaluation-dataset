// Java
public class Solution {
    public void findSecretWord(String[] words, Master master) {
        for (int i = 0; i < 10; i++) {
            int guessIndex = (int) (Math.random() * words.length);
            String guess = words[guessIndex];
            int matches = master.guess(guess);
            if (matches == 6) {
                System.out.println("You guessed the secret word correctly.");
                return;
            }
            List<String> newWords = new ArrayList<>();
            for (String word : words) {
                if (match(word, guess, matches)) {
                    newWords.add(word);
                }
            }
            words = newWords.toArray(new String[0]);
        }
        System.out.println("Either you took too many guesses, or you did not find the secret word.");
    }

    private boolean match(String word, String guess, int matches) {
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == guess.charAt(i)) {
                count++;
            }
        }
        return count == matches;
    }
}