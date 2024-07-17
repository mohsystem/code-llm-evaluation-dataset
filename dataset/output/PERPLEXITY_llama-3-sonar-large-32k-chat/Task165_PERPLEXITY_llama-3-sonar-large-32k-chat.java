public class Main {
    public static boolean checkFlush(String[] table, String[] hand) {
        int[] suits = new int[4];
        for (String card : table) {
            char suit = card.charAt(card.length() - 1);
            switch (suit) {
                case 'S':
                    suits[0]++;
                    break;
                case 'H':
                    suits[1]++;
                    break;
                case 'D':
                    suits[2]++;
                    break;
                case 'C':
                    suits[3]++;
                    break;
            }
        }
        for (String card : hand) {
            char suit = card.charAt(card.length() - 1);
            switch (suit) {
                case 'S':
                    suits[0]++;
                    break;
                case 'H':
                    suits[1]++;
                    break;
                case 'D':
                    suits[2]++;
                    break;
                case 'C':
                    suits[3]++;
                    break;
            }
        }
        for (int count : suits) {
            if (count >= 5) {
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        String[] table = {"A_S", "J_H", "7_D", "8_D", "10_D"};
        String[] hand = {"J_D", "3_D"};
        System.out.println(checkFlush(table, hand));
    }
}