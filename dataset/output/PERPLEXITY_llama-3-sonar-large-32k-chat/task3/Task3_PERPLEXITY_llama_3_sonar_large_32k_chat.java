import java.util.*;

public class Task3_PERPLEXITY_llama_3_sonar_large_32k_chat {
    public static boolean isPangram(String s) {
        String alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (char c : alphabet.toCharArray()) {
            if (!s.toLowerCase().contains(String.valueOf(c))) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isPangram("The quick brown fox jumps over the lazy dog"));  // true
        System.out.println(isPangram("Hello World"));  // false
    }
}