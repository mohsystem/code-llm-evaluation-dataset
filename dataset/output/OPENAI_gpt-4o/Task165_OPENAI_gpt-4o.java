import java.util.*;

public class Main {
    public static boolean checkFlush(String[] tableCards, String[] handCards) {
        Map<Character, Integer> suits = new HashMap<>();
        suits.put('S', 0);
        suits.put('H', 0);
        suits.put('D', 0);
        suits.put('C', 0);
        
        String[] cards = new String[tableCards.length + handCards.length];
        System.arraycopy(tableCards, 0, cards, 0, tableCards.length);
        System.arraycopy(handCards, 0, cards, tableCards.length, handCards.length);
        
        for (String card : cards) {
            char suit = card.split("_")[1].charAt(0);
            suits.put(suit, suits.get(suit) + 1);
        }
        
        for (int count : suits.values()) {
            if (count >= 5) {
                return true;
            }
        }
        return false;
    }
    
    public static void main(String[] args) {
        System.out.println(checkFlush(new String[]{"A_S", "J_H", "7_D", "8_D", "10_D"}, new String[]{"J_D", "3_D"})); // ➞ true
        System.out.println(checkFlush(new String[]{"10_S", "7_S", "9_H", "4_S", "3_S"}, new String[]{"K_S", "Q_S"})); // ➞ true
        System.out.println(checkFlush(new String[]{"3_S", "10_H", "10_D", "10_C", "10_S"}, new String[]{"3_S", "4_D"})); // ➞ false
    }
}