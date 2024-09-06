import java.util.*;

class Master {
    private String secret;
    private int guessCount;

    public Master(String secret) {
        this.secret = secret;
    }

    public int guess(String word) {
        guessCount++;
        if (!Arrays.asList(words).contains(word)) {
            return -1;
        }
        int matches = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret.charAt(i) == word.charAt(i)) {
                matches++;
            }
        }
        return matches;
    }
}

public class Task194_OPENAI_gpt_4o {

    public static void findSecretWord(String[] words, Master master, int allowedGuesses) {
        for (int i = 0; i < allowedGuesses; i++) {
            String guessWord = words[new Random().nextInt(words.length)];
            int matches = master.guess(guessWord);
            if (matches == 6) {
                System.out.println("You guessed the secret word correctly.");
                return;
            }
            List<String> newWords = new ArrayList<>();
            for (String word : words) {
                if (matchCount(word, guessWord) == matches) {
                    newWords.add(word);
                }
            }
            words = newWords.toArray(new String[0]);
        }
        System.out.println("Either you took too many guesses, or you did not find the secret word.");
    }

    private static int matchCount(String w1, String w2) {
        int matches = 0;
        for (int i = 0; i < w1.length(); i++) {
            if (w1.charAt(i) == w2.charAt(i)) {
                matches++;
            }
        }
        return matches;
    }

    public static void main(String[] args) {
        String secret = "acckzz";
        String[] words = {"acckzz", "ccbazz", "eiowzz", "abcczz"};
        int allowedGuesses = 10;
        Master master = new Master(secret);
        findSecretWord(words, master, allowedGuesses);
    }
}