import java.util.*;

class Master {
    private String secret;
    private int guessCount;

    public Master(String secret) {
        this.secret = secret;
        this.guessCount = 0;
    }

    public int guess(String word) {
        this.guessCount++;
        if (!Arrays.asList(words).contains(word)) {
            return -1;
        }
        return (int) IntStream.range(0, secret.length()).filter(i -> secret.charAt(i) == word.charAt(i)).count();
    }
}

public class Solution {
    private static String[] words = {"hamada","khaled"};
    private static int allowedGuesses = 10;

    public static void main(String[] args) {
        String secret = "hamada";
        Master master = new Master(secret);
        findSecretWord(words, master);
    }

    public static void findSecretWord(String[] words, Master master) {
        int attempts = 0;
        Random rand = new Random();
        while (attempts < allowedGuesses) {
            String guessWord = words[rand.nextInt(words.length)];
            int matches = master.guess(guessWord);
            if (matches == 6) {
                System.out.println("You guessed the secret word correctly.");
                return;
            }
            List<String> filteredWords = new ArrayList<String>();
            for (String word : words) {
                if (match(word, guessWord) == matches) {
                    filteredWords.add(word);
                }
            }
            words = filteredWords.toArray(new String[0]);
            attempts++;
        }
        System.out.println("Either you took too many guesses, or you did not find the secret word.");
    }

    private static int match(String word1, String word2) {
        int matches = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1.charAt(i) == word2.charAt(i)) {
                matches++;
            }
        }
        return matches;
    }
}