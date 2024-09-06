
public class Task12_CLAUDE_claude_3_5_sonnet_20240620 {
    public static String high(String s) {
        String[] words = s.split(" ");
        int maxScore = 0;
        String maxWord = "";
        
        for (String word : words) {
            int score = 0;
            for (char c : word.toCharArray()) {
                score += c - 'a' + 1;
            }
            if (score > maxScore) {
                maxScore = score;
                maxWord = word;
            }
        }
        
        return maxWord;
    }

    public static void main(String[] args) {
        System.out.println(high("man i need a taxi up to ubud")); // Output: taxi
        System.out.println(high("what time are we climbing up the volcano")); // Output: volcano
        System.out.println(high("take me to semynak")); // Output: semynak
    }
}
