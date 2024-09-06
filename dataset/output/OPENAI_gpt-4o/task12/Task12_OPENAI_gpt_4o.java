import java.util.StringTokenizer;

public class Task12_OPENAI_gpt_4o {
    public static void main(String[] args) {
        String inputString = "abad test example";
        System.out.println(high(inputString));
    }

    public static String high(String inputString) {
        StringTokenizer tokenizer = new StringTokenizer(inputString);
        String bestWord = "";
        int maxScore = 0;

        while (tokenizer.hasMoreTokens()) {
            String word = tokenizer.nextToken();
            int score = calculateScore(word);

            if (score > maxScore) {
                maxScore = score;
                bestWord = word;
            }
        }

        return bestWord;
    }

    private static int calculateScore(String word) {
        int score = 0;
        for (char c : word.toCharArray()) {
            score += c - 'a' + 1;
        }
        return score;
    }
}