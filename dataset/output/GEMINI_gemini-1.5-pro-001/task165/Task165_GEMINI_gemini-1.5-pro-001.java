import java.util.HashMap;
class Solution {
    public boolean checkFlush(String[] table, String[] hand) {
      HashMap<Character, Integer> suits = new HashMap<>();
      suits.put('S', 0);
      suits.put('H', 0);
      suits.put('D', 0);
      suits.put('C', 0);
      for (String card : table) {
        suits.put(card.charAt(card.length()-1), suits.get(card.charAt(card.length()-1)) + 1);
      }
      for (String card : hand) {
        suits.put(card.charAt(card.length()-1), suits.get(card.charAt(card.length()-1)) + 1);
      }
      for (int val : suits.values()) {
        if (val >= 5) {
          return true;
        }
      }
      return false;
    }
}