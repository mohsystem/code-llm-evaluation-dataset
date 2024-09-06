public class Task12_GEMINI_gemini_1_5_pro_001 {
    public static String high(String s) {
        String[] words = s.split(" ");
        int highestScore = 0;
        String highestWord = "";
        for (String word : words) {
            int score = 0;
            for (char c : word.toCharArray()) {
                score += c - 'a' + 1;
            }
            if (score > highestScore) {
                highestScore = score;
                highestWord = word;
            }
        }
        return highestWord;
    }
}