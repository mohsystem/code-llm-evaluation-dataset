import java.util.*;

class Solution {
    public void findSecretWord(String[] wordlist, Master master) {
        for (int i = 0; i < 10; i++) {
            String guess = wordlist[new Random().nextInt(wordlist.length)];
            int result = master.guess(guess);
            if (result == 6) return;
            List<String> newList = new ArrayList<>();
            for (String word : wordlist) {
                if (match(word, guess) == result) newList.add(word);
            }
            wordlist = newList.toArray(new String[0]);
        }
    }

    private int match(String word1, String word2) {
        int count = 0;
        for (int i = 0; i < 6; i++) {
            if (word1.charAt(i) == word2.charAt(i)) count++;
        }
        return count;
    }
}