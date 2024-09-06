public class Task12_MISTRAL_codestral_latest {
    public static String highScoringWord(String inputString) {
        String[] words = inputString.split(" ");
        int[] scores = new int[words.length];
        int maxScore = Integer.MIN_VALUE;
        String maxWord = "";

        for (int i = 0; i < words.length; i++) {
            for (char c : words[i].toCharArray()) {
                scores[i] += c - 'a' + 1;
            }
            if (scores[i] > maxScore) {
                maxScore = scores[i];
                maxWord = words[i];
            }
        }

        return maxWord;
    }
}