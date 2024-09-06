import java.util.*;

class Solution {
    public void findSecretWord(String[] wordlist, Master master) {
        for (int i = 0; i < 10; i++) {
            String guess = wordlist[new Random().nextInt(wordlist.length)];
            int res = master.guess(guess);
            if (res == 6) return;
            List<String> newList = new ArrayList<>();
            for (String w : wordlist) {
                int match = 0;
                for (int j = 0; j < 6; j++) {
                    if (w.charAt(j) == guess.charAt(j)) match++;
                }
                if (match == res) newList.add(w);
            }
            wordlist = newList.toArray(new String[0]);
        }
    }
}