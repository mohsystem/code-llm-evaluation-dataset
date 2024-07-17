import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        String input = "example input sentence";
        System.out.println(highestScoringWord(input));
    }

    private static String highestScoringWord(String str) {
        return Arrays.stream(str.split(" "))
                .max((w1, w2) -> Integer.compare(wordScore(w1), wordScore(w2)))
                .orElse("");
    }

    private static int wordScore(String word) {
        return word.chars().map(c -> c - 'a' + 1).sum();
    }
}