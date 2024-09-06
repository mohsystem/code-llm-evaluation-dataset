import java.util.*;

public class Task165_MISTRAL_codestral_latest {
    public static boolean checkFlush(String[] table, String[] hand) {
        Map<Character, Integer> suitCount = new HashMap<>();
        for (String card : table)
            suitCount.put(card.charAt(card.length() - 1), suitCount.getOrDefault(card.charAt(card.length() - 1), 0) + 1);
        for (String card : hand)
            suitCount.put(card.charAt(card.length() - 1), suitCount.getOrDefault(card.charAt(card.length() - 1), 0) + 1);
        for (char suit : "SHDC".toCharArray())
            if (suitCount.getOrDefault(suit, 0) >= 5)
                return true;
        return false;
    }
}