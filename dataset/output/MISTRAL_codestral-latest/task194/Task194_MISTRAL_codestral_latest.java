// Java code
public class Task194_MISTRAL_codestral_latest {
    public void findSecretWord(String[] words, Master master) {
        int matches(String a, String b) {
            int count = 0;
            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) == b.charAt(i)) {
                    count++;
                }
            }
            return count;
        }

        void findSecretWord(List<String> possibleWords) {
            if (possibleWords.isEmpty()) {
                return;
            }
            if (possibleWords.size() == 1) {
                master.guess(possibleWords.get(0));
                return;
            }

            // Choose a word with the least number of matches with other words
            int[] wordCount = new int[possibleWords.size()];
            for (int i = 0; i < possibleWords.size(); i++) {
                for (int j = i + 1; j < possibleWords.size(); j++) {
                    int matches = matches(possibleWords.get(i), possibleWords.get(j));
                    wordCount[i] += matches;
                    wordCount[j] += matches;
                }
            }
            int minCount = Integer.MAX_VALUE;
            int minIndex = 0;
            for (int i = 0; i < wordCount.length; i++) {
                if (wordCount[i] < minCount) {
                    minCount = wordCount[i];
                    minIndex = i;
                }
            }
            String guess = possibleWords.get(minIndex);

            int matches = master.guess(guess);
            if (matches == 6) {
                return;
            }

            // Filter out words that don't match the number of matches with the guess
            List<String> newPossibleWords = new ArrayList<>();
            for (String word : possibleWords) {
                if (matches(word, guess) == matches) {
                    newPossibleWords.add(word);
                }
            }
            findSecretWord(newPossibleWords);
        }

        findSecretWord(Arrays.asList(words));
    }
}