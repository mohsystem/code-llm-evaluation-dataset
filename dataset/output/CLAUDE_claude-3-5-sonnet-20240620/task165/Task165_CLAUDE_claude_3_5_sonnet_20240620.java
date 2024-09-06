
import java.util.*;

public class Task165_CLAUDE_claude_3_5_sonnet_20240620 {
    public static boolean checkFlush(String[] table, String[] hand) {
        Map<Character, Integer> suits = new HashMap<>();
        suits.put('S', 0);
        suits.put('H', 0);
        suits.put('D', 0);
        suits.put('C', 0);
        
        for (String card : table) {
            suits.put(card.charAt(card.length() - 1), suits.get(card.charAt(card.length() - 1)) + 1);
        }
        for (String card : hand) {
            suits.put(card.charAt(card.length() - 1), suits.get(card.charAt(card.length() - 1)) + 1);
        }
        
        return Collections.max(suits.values()) >= 5;
    }

    public static void main(String[] args) {
        System.out.println(checkFlush(new String[]{"A_S", "J_H", "7_D", "8_D", "10_D"}, new String[]{"J_D", "3_D"}));  // true
        System.out.println(checkFlush(new String[]{"10_S", "7_S", "9_H", "4_S", "3_S"}, new String[]{"K_S", "Q_S"}));  // true
        System.out.println(checkFlush(new String[]{"3_S", "10_H", "10_D", "10_C", "10_S"}, new String[]{"3_S", "4_D"}));  // false
    }
}
